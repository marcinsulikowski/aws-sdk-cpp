﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/core/utils/Outcome.h>
#include <aws/core/auth/AWSAuthSigner.h>
#include <aws/core/client/CoreErrors.h>
#include <aws/core/client/RetryStrategy.h>
#include <aws/core/http/HttpClient.h>
#include <aws/core/http/HttpResponse.h>
#include <aws/core/http/HttpClientFactory.h>
#include <aws/core/auth/AWSCredentialsProviderChain.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/core/utils/threading/Executor.h>
#include <aws/core/utils/DNS.h>
#include <aws/core/utils/logging/LogMacros.h>

#include <aws/cognito-idp/CognitoIdentityProviderClient.h>
#include <aws/cognito-idp/CognitoIdentityProviderEndpoint.h>
#include <aws/cognito-idp/CognitoIdentityProviderErrorMarshaller.h>
#include <aws/cognito-idp/model/AddCustomAttributesRequest.h>
#include <aws/cognito-idp/model/AdminAddUserToGroupRequest.h>
#include <aws/cognito-idp/model/AdminConfirmSignUpRequest.h>
#include <aws/cognito-idp/model/AdminCreateUserRequest.h>
#include <aws/cognito-idp/model/AdminDeleteUserRequest.h>
#include <aws/cognito-idp/model/AdminDeleteUserAttributesRequest.h>
#include <aws/cognito-idp/model/AdminDisableProviderForUserRequest.h>
#include <aws/cognito-idp/model/AdminDisableUserRequest.h>
#include <aws/cognito-idp/model/AdminEnableUserRequest.h>
#include <aws/cognito-idp/model/AdminForgetDeviceRequest.h>
#include <aws/cognito-idp/model/AdminGetDeviceRequest.h>
#include <aws/cognito-idp/model/AdminGetUserRequest.h>
#include <aws/cognito-idp/model/AdminInitiateAuthRequest.h>
#include <aws/cognito-idp/model/AdminLinkProviderForUserRequest.h>
#include <aws/cognito-idp/model/AdminListDevicesRequest.h>
#include <aws/cognito-idp/model/AdminListGroupsForUserRequest.h>
#include <aws/cognito-idp/model/AdminListUserAuthEventsRequest.h>
#include <aws/cognito-idp/model/AdminRemoveUserFromGroupRequest.h>
#include <aws/cognito-idp/model/AdminResetUserPasswordRequest.h>
#include <aws/cognito-idp/model/AdminRespondToAuthChallengeRequest.h>
#include <aws/cognito-idp/model/AdminSetUserMFAPreferenceRequest.h>
#include <aws/cognito-idp/model/AdminSetUserPasswordRequest.h>
#include <aws/cognito-idp/model/AdminSetUserSettingsRequest.h>
#include <aws/cognito-idp/model/AdminUpdateAuthEventFeedbackRequest.h>
#include <aws/cognito-idp/model/AdminUpdateDeviceStatusRequest.h>
#include <aws/cognito-idp/model/AdminUpdateUserAttributesRequest.h>
#include <aws/cognito-idp/model/AdminUserGlobalSignOutRequest.h>
#include <aws/cognito-idp/model/AssociateSoftwareTokenRequest.h>
#include <aws/cognito-idp/model/ChangePasswordRequest.h>
#include <aws/cognito-idp/model/ConfirmDeviceRequest.h>
#include <aws/cognito-idp/model/ConfirmForgotPasswordRequest.h>
#include <aws/cognito-idp/model/ConfirmSignUpRequest.h>
#include <aws/cognito-idp/model/CreateGroupRequest.h>
#include <aws/cognito-idp/model/CreateIdentityProviderRequest.h>
#include <aws/cognito-idp/model/CreateResourceServerRequest.h>
#include <aws/cognito-idp/model/CreateUserImportJobRequest.h>
#include <aws/cognito-idp/model/CreateUserPoolRequest.h>
#include <aws/cognito-idp/model/CreateUserPoolClientRequest.h>
#include <aws/cognito-idp/model/CreateUserPoolDomainRequest.h>
#include <aws/cognito-idp/model/DeleteGroupRequest.h>
#include <aws/cognito-idp/model/DeleteIdentityProviderRequest.h>
#include <aws/cognito-idp/model/DeleteResourceServerRequest.h>
#include <aws/cognito-idp/model/DeleteUserRequest.h>
#include <aws/cognito-idp/model/DeleteUserAttributesRequest.h>
#include <aws/cognito-idp/model/DeleteUserPoolRequest.h>
#include <aws/cognito-idp/model/DeleteUserPoolClientRequest.h>
#include <aws/cognito-idp/model/DeleteUserPoolDomainRequest.h>
#include <aws/cognito-idp/model/DescribeIdentityProviderRequest.h>
#include <aws/cognito-idp/model/DescribeResourceServerRequest.h>
#include <aws/cognito-idp/model/DescribeRiskConfigurationRequest.h>
#include <aws/cognito-idp/model/DescribeUserImportJobRequest.h>
#include <aws/cognito-idp/model/DescribeUserPoolRequest.h>
#include <aws/cognito-idp/model/DescribeUserPoolClientRequest.h>
#include <aws/cognito-idp/model/DescribeUserPoolDomainRequest.h>
#include <aws/cognito-idp/model/ForgetDeviceRequest.h>
#include <aws/cognito-idp/model/ForgotPasswordRequest.h>
#include <aws/cognito-idp/model/GetCSVHeaderRequest.h>
#include <aws/cognito-idp/model/GetDeviceRequest.h>
#include <aws/cognito-idp/model/GetGroupRequest.h>
#include <aws/cognito-idp/model/GetIdentityProviderByIdentifierRequest.h>
#include <aws/cognito-idp/model/GetSigningCertificateRequest.h>
#include <aws/cognito-idp/model/GetUICustomizationRequest.h>
#include <aws/cognito-idp/model/GetUserRequest.h>
#include <aws/cognito-idp/model/GetUserAttributeVerificationCodeRequest.h>
#include <aws/cognito-idp/model/GetUserPoolMfaConfigRequest.h>
#include <aws/cognito-idp/model/GlobalSignOutRequest.h>
#include <aws/cognito-idp/model/InitiateAuthRequest.h>
#include <aws/cognito-idp/model/ListDevicesRequest.h>
#include <aws/cognito-idp/model/ListGroupsRequest.h>
#include <aws/cognito-idp/model/ListIdentityProvidersRequest.h>
#include <aws/cognito-idp/model/ListResourceServersRequest.h>
#include <aws/cognito-idp/model/ListTagsForResourceRequest.h>
#include <aws/cognito-idp/model/ListUserImportJobsRequest.h>
#include <aws/cognito-idp/model/ListUserPoolClientsRequest.h>
#include <aws/cognito-idp/model/ListUserPoolsRequest.h>
#include <aws/cognito-idp/model/ListUsersRequest.h>
#include <aws/cognito-idp/model/ListUsersInGroupRequest.h>
#include <aws/cognito-idp/model/ResendConfirmationCodeRequest.h>
#include <aws/cognito-idp/model/RespondToAuthChallengeRequest.h>
#include <aws/cognito-idp/model/RevokeTokenRequest.h>
#include <aws/cognito-idp/model/SetRiskConfigurationRequest.h>
#include <aws/cognito-idp/model/SetUICustomizationRequest.h>
#include <aws/cognito-idp/model/SetUserMFAPreferenceRequest.h>
#include <aws/cognito-idp/model/SetUserPoolMfaConfigRequest.h>
#include <aws/cognito-idp/model/SetUserSettingsRequest.h>
#include <aws/cognito-idp/model/SignUpRequest.h>
#include <aws/cognito-idp/model/StartUserImportJobRequest.h>
#include <aws/cognito-idp/model/StopUserImportJobRequest.h>
#include <aws/cognito-idp/model/TagResourceRequest.h>
#include <aws/cognito-idp/model/UntagResourceRequest.h>
#include <aws/cognito-idp/model/UpdateAuthEventFeedbackRequest.h>
#include <aws/cognito-idp/model/UpdateDeviceStatusRequest.h>
#include <aws/cognito-idp/model/UpdateGroupRequest.h>
#include <aws/cognito-idp/model/UpdateIdentityProviderRequest.h>
#include <aws/cognito-idp/model/UpdateResourceServerRequest.h>
#include <aws/cognito-idp/model/UpdateUserAttributesRequest.h>
#include <aws/cognito-idp/model/UpdateUserPoolRequest.h>
#include <aws/cognito-idp/model/UpdateUserPoolClientRequest.h>
#include <aws/cognito-idp/model/UpdateUserPoolDomainRequest.h>
#include <aws/cognito-idp/model/VerifySoftwareTokenRequest.h>
#include <aws/cognito-idp/model/VerifyUserAttributeRequest.h>

using namespace Aws;
using namespace Aws::Auth;
using namespace Aws::Client;
using namespace Aws::CognitoIdentityProvider;
using namespace Aws::CognitoIdentityProvider::Model;
using namespace Aws::Http;
using namespace Aws::Utils::Json;

static const char* SERVICE_NAME = "cognito-idp";
static const char* ALLOCATION_TAG = "CognitoIdentityProviderClient";

CognitoIdentityProviderClient::CognitoIdentityProviderClient(const Client::ClientConfiguration& clientConfiguration) :
  BASECLASS(clientConfiguration,
            Aws::MakeShared<AWSAuthV4Signer>(ALLOCATION_TAG,
                                             Aws::MakeShared<DefaultAWSCredentialsProviderChain>(ALLOCATION_TAG),
                                             SERVICE_NAME,
                                             Aws::Region::ComputeSignerRegion(clientConfiguration.region)),
            Aws::MakeShared<CognitoIdentityProviderErrorMarshaller>(ALLOCATION_TAG)),
  m_executor(clientConfiguration.executor)
{
  init(clientConfiguration);
}

CognitoIdentityProviderClient::CognitoIdentityProviderClient(const AWSCredentials& credentials,
                                                             const Client::ClientConfiguration& clientConfiguration) :
  BASECLASS(clientConfiguration,
            Aws::MakeShared<AWSAuthV4Signer>(ALLOCATION_TAG,
                                             Aws::MakeShared<SimpleAWSCredentialsProvider>(ALLOCATION_TAG, credentials),
                                             SERVICE_NAME,
                                             Aws::Region::ComputeSignerRegion(clientConfiguration.region)),
            Aws::MakeShared<CognitoIdentityProviderErrorMarshaller>(ALLOCATION_TAG)),
    m_executor(clientConfiguration.executor)
{
  init(clientConfiguration);
}

CognitoIdentityProviderClient::CognitoIdentityProviderClient(const std::shared_ptr<AWSCredentialsProvider>& credentialsProvider,
                                                             const Client::ClientConfiguration& clientConfiguration) :
  BASECLASS(clientConfiguration,
            Aws::MakeShared<AWSAuthV4Signer>(ALLOCATION_TAG,
                                             credentialsProvider,
                                             SERVICE_NAME,
                                             Aws::Region::ComputeSignerRegion(clientConfiguration.region)),
            Aws::MakeShared<CognitoIdentityProviderErrorMarshaller>(ALLOCATION_TAG)),
    m_executor(clientConfiguration.executor)
{
  init(clientConfiguration);
}

CognitoIdentityProviderClient::~CognitoIdentityProviderClient()
{
}

void CognitoIdentityProviderClient::init(const Client::ClientConfiguration& config)
{
  AWSClient::SetServiceClientName("Cognito Identity Provider");
  m_configScheme = SchemeMapper::ToString(config.scheme);
  if (config.endpointOverride.empty())
  {
      m_uri = m_configScheme + "://" + CognitoIdentityProviderEndpoint::ForRegion(config.region, config.useDualStack);
  }
  else
  {
      OverrideEndpoint(config.endpointOverride);
  }
}

void CognitoIdentityProviderClient::OverrideEndpoint(const Aws::String& endpoint)
{
  if (endpoint.compare(0, 7, "http://") == 0 || endpoint.compare(0, 8, "https://") == 0)
  {
      m_uri = endpoint;
  }
  else
  {
      m_uri = m_configScheme + "://" + endpoint;
  }
}

AddCustomAttributesOutcome CognitoIdentityProviderClient::AddCustomAttributes(const AddCustomAttributesRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AddCustomAttributesOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AddCustomAttributesOutcomeCallable CognitoIdentityProviderClient::AddCustomAttributesCallable(const AddCustomAttributesRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AddCustomAttributesOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AddCustomAttributes(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AddCustomAttributesAsync(const AddCustomAttributesRequest& request, const AddCustomAttributesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AddCustomAttributes(request), context);
    } );
}

AdminAddUserToGroupOutcome CognitoIdentityProviderClient::AdminAddUserToGroup(const AdminAddUserToGroupRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminAddUserToGroupOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminAddUserToGroupOutcomeCallable CognitoIdentityProviderClient::AdminAddUserToGroupCallable(const AdminAddUserToGroupRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminAddUserToGroupOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminAddUserToGroup(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminAddUserToGroupAsync(const AdminAddUserToGroupRequest& request, const AdminAddUserToGroupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminAddUserToGroup(request), context);
    } );
}

AdminConfirmSignUpOutcome CognitoIdentityProviderClient::AdminConfirmSignUp(const AdminConfirmSignUpRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminConfirmSignUpOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminConfirmSignUpOutcomeCallable CognitoIdentityProviderClient::AdminConfirmSignUpCallable(const AdminConfirmSignUpRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminConfirmSignUpOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminConfirmSignUp(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminConfirmSignUpAsync(const AdminConfirmSignUpRequest& request, const AdminConfirmSignUpResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminConfirmSignUp(request), context);
    } );
}

AdminCreateUserOutcome CognitoIdentityProviderClient::AdminCreateUser(const AdminCreateUserRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminCreateUserOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminCreateUserOutcomeCallable CognitoIdentityProviderClient::AdminCreateUserCallable(const AdminCreateUserRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminCreateUserOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminCreateUser(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminCreateUserAsync(const AdminCreateUserRequest& request, const AdminCreateUserResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminCreateUser(request), context);
    } );
}

AdminDeleteUserOutcome CognitoIdentityProviderClient::AdminDeleteUser(const AdminDeleteUserRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminDeleteUserOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminDeleteUserOutcomeCallable CognitoIdentityProviderClient::AdminDeleteUserCallable(const AdminDeleteUserRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminDeleteUserOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminDeleteUser(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminDeleteUserAsync(const AdminDeleteUserRequest& request, const AdminDeleteUserResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminDeleteUser(request), context);
    } );
}

AdminDeleteUserAttributesOutcome CognitoIdentityProviderClient::AdminDeleteUserAttributes(const AdminDeleteUserAttributesRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminDeleteUserAttributesOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminDeleteUserAttributesOutcomeCallable CognitoIdentityProviderClient::AdminDeleteUserAttributesCallable(const AdminDeleteUserAttributesRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminDeleteUserAttributesOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminDeleteUserAttributes(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminDeleteUserAttributesAsync(const AdminDeleteUserAttributesRequest& request, const AdminDeleteUserAttributesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminDeleteUserAttributes(request), context);
    } );
}

AdminDisableProviderForUserOutcome CognitoIdentityProviderClient::AdminDisableProviderForUser(const AdminDisableProviderForUserRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminDisableProviderForUserOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminDisableProviderForUserOutcomeCallable CognitoIdentityProviderClient::AdminDisableProviderForUserCallable(const AdminDisableProviderForUserRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminDisableProviderForUserOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminDisableProviderForUser(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminDisableProviderForUserAsync(const AdminDisableProviderForUserRequest& request, const AdminDisableProviderForUserResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminDisableProviderForUser(request), context);
    } );
}

AdminDisableUserOutcome CognitoIdentityProviderClient::AdminDisableUser(const AdminDisableUserRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminDisableUserOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminDisableUserOutcomeCallable CognitoIdentityProviderClient::AdminDisableUserCallable(const AdminDisableUserRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminDisableUserOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminDisableUser(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminDisableUserAsync(const AdminDisableUserRequest& request, const AdminDisableUserResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminDisableUser(request), context);
    } );
}

AdminEnableUserOutcome CognitoIdentityProviderClient::AdminEnableUser(const AdminEnableUserRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminEnableUserOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminEnableUserOutcomeCallable CognitoIdentityProviderClient::AdminEnableUserCallable(const AdminEnableUserRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminEnableUserOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminEnableUser(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminEnableUserAsync(const AdminEnableUserRequest& request, const AdminEnableUserResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminEnableUser(request), context);
    } );
}

AdminForgetDeviceOutcome CognitoIdentityProviderClient::AdminForgetDevice(const AdminForgetDeviceRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminForgetDeviceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminForgetDeviceOutcomeCallable CognitoIdentityProviderClient::AdminForgetDeviceCallable(const AdminForgetDeviceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminForgetDeviceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminForgetDevice(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminForgetDeviceAsync(const AdminForgetDeviceRequest& request, const AdminForgetDeviceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminForgetDevice(request), context);
    } );
}

AdminGetDeviceOutcome CognitoIdentityProviderClient::AdminGetDevice(const AdminGetDeviceRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminGetDeviceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminGetDeviceOutcomeCallable CognitoIdentityProviderClient::AdminGetDeviceCallable(const AdminGetDeviceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminGetDeviceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminGetDevice(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminGetDeviceAsync(const AdminGetDeviceRequest& request, const AdminGetDeviceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminGetDevice(request), context);
    } );
}

AdminGetUserOutcome CognitoIdentityProviderClient::AdminGetUser(const AdminGetUserRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminGetUserOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminGetUserOutcomeCallable CognitoIdentityProviderClient::AdminGetUserCallable(const AdminGetUserRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminGetUserOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminGetUser(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminGetUserAsync(const AdminGetUserRequest& request, const AdminGetUserResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminGetUser(request), context);
    } );
}

AdminInitiateAuthOutcome CognitoIdentityProviderClient::AdminInitiateAuth(const AdminInitiateAuthRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminInitiateAuthOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminInitiateAuthOutcomeCallable CognitoIdentityProviderClient::AdminInitiateAuthCallable(const AdminInitiateAuthRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminInitiateAuthOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminInitiateAuth(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminInitiateAuthAsync(const AdminInitiateAuthRequest& request, const AdminInitiateAuthResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminInitiateAuth(request), context);
    } );
}

AdminLinkProviderForUserOutcome CognitoIdentityProviderClient::AdminLinkProviderForUser(const AdminLinkProviderForUserRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminLinkProviderForUserOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminLinkProviderForUserOutcomeCallable CognitoIdentityProviderClient::AdminLinkProviderForUserCallable(const AdminLinkProviderForUserRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminLinkProviderForUserOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminLinkProviderForUser(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminLinkProviderForUserAsync(const AdminLinkProviderForUserRequest& request, const AdminLinkProviderForUserResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminLinkProviderForUser(request), context);
    } );
}

AdminListDevicesOutcome CognitoIdentityProviderClient::AdminListDevices(const AdminListDevicesRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminListDevicesOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminListDevicesOutcomeCallable CognitoIdentityProviderClient::AdminListDevicesCallable(const AdminListDevicesRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminListDevicesOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminListDevices(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminListDevicesAsync(const AdminListDevicesRequest& request, const AdminListDevicesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminListDevices(request), context);
    } );
}

AdminListGroupsForUserOutcome CognitoIdentityProviderClient::AdminListGroupsForUser(const AdminListGroupsForUserRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminListGroupsForUserOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminListGroupsForUserOutcomeCallable CognitoIdentityProviderClient::AdminListGroupsForUserCallable(const AdminListGroupsForUserRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminListGroupsForUserOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminListGroupsForUser(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminListGroupsForUserAsync(const AdminListGroupsForUserRequest& request, const AdminListGroupsForUserResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminListGroupsForUser(request), context);
    } );
}

AdminListUserAuthEventsOutcome CognitoIdentityProviderClient::AdminListUserAuthEvents(const AdminListUserAuthEventsRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminListUserAuthEventsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminListUserAuthEventsOutcomeCallable CognitoIdentityProviderClient::AdminListUserAuthEventsCallable(const AdminListUserAuthEventsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminListUserAuthEventsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminListUserAuthEvents(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminListUserAuthEventsAsync(const AdminListUserAuthEventsRequest& request, const AdminListUserAuthEventsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminListUserAuthEvents(request), context);
    } );
}

AdminRemoveUserFromGroupOutcome CognitoIdentityProviderClient::AdminRemoveUserFromGroup(const AdminRemoveUserFromGroupRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminRemoveUserFromGroupOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminRemoveUserFromGroupOutcomeCallable CognitoIdentityProviderClient::AdminRemoveUserFromGroupCallable(const AdminRemoveUserFromGroupRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminRemoveUserFromGroupOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminRemoveUserFromGroup(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminRemoveUserFromGroupAsync(const AdminRemoveUserFromGroupRequest& request, const AdminRemoveUserFromGroupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminRemoveUserFromGroup(request), context);
    } );
}

AdminResetUserPasswordOutcome CognitoIdentityProviderClient::AdminResetUserPassword(const AdminResetUserPasswordRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminResetUserPasswordOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminResetUserPasswordOutcomeCallable CognitoIdentityProviderClient::AdminResetUserPasswordCallable(const AdminResetUserPasswordRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminResetUserPasswordOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminResetUserPassword(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminResetUserPasswordAsync(const AdminResetUserPasswordRequest& request, const AdminResetUserPasswordResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminResetUserPassword(request), context);
    } );
}

AdminRespondToAuthChallengeOutcome CognitoIdentityProviderClient::AdminRespondToAuthChallenge(const AdminRespondToAuthChallengeRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminRespondToAuthChallengeOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminRespondToAuthChallengeOutcomeCallable CognitoIdentityProviderClient::AdminRespondToAuthChallengeCallable(const AdminRespondToAuthChallengeRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminRespondToAuthChallengeOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminRespondToAuthChallenge(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminRespondToAuthChallengeAsync(const AdminRespondToAuthChallengeRequest& request, const AdminRespondToAuthChallengeResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminRespondToAuthChallenge(request), context);
    } );
}

AdminSetUserMFAPreferenceOutcome CognitoIdentityProviderClient::AdminSetUserMFAPreference(const AdminSetUserMFAPreferenceRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminSetUserMFAPreferenceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminSetUserMFAPreferenceOutcomeCallable CognitoIdentityProviderClient::AdminSetUserMFAPreferenceCallable(const AdminSetUserMFAPreferenceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminSetUserMFAPreferenceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminSetUserMFAPreference(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminSetUserMFAPreferenceAsync(const AdminSetUserMFAPreferenceRequest& request, const AdminSetUserMFAPreferenceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminSetUserMFAPreference(request), context);
    } );
}

AdminSetUserPasswordOutcome CognitoIdentityProviderClient::AdminSetUserPassword(const AdminSetUserPasswordRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminSetUserPasswordOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminSetUserPasswordOutcomeCallable CognitoIdentityProviderClient::AdminSetUserPasswordCallable(const AdminSetUserPasswordRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminSetUserPasswordOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminSetUserPassword(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminSetUserPasswordAsync(const AdminSetUserPasswordRequest& request, const AdminSetUserPasswordResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminSetUserPassword(request), context);
    } );
}

AdminSetUserSettingsOutcome CognitoIdentityProviderClient::AdminSetUserSettings(const AdminSetUserSettingsRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminSetUserSettingsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminSetUserSettingsOutcomeCallable CognitoIdentityProviderClient::AdminSetUserSettingsCallable(const AdminSetUserSettingsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminSetUserSettingsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminSetUserSettings(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminSetUserSettingsAsync(const AdminSetUserSettingsRequest& request, const AdminSetUserSettingsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminSetUserSettings(request), context);
    } );
}

AdminUpdateAuthEventFeedbackOutcome CognitoIdentityProviderClient::AdminUpdateAuthEventFeedback(const AdminUpdateAuthEventFeedbackRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminUpdateAuthEventFeedbackOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminUpdateAuthEventFeedbackOutcomeCallable CognitoIdentityProviderClient::AdminUpdateAuthEventFeedbackCallable(const AdminUpdateAuthEventFeedbackRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminUpdateAuthEventFeedbackOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminUpdateAuthEventFeedback(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminUpdateAuthEventFeedbackAsync(const AdminUpdateAuthEventFeedbackRequest& request, const AdminUpdateAuthEventFeedbackResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminUpdateAuthEventFeedback(request), context);
    } );
}

AdminUpdateDeviceStatusOutcome CognitoIdentityProviderClient::AdminUpdateDeviceStatus(const AdminUpdateDeviceStatusRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminUpdateDeviceStatusOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminUpdateDeviceStatusOutcomeCallable CognitoIdentityProviderClient::AdminUpdateDeviceStatusCallable(const AdminUpdateDeviceStatusRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminUpdateDeviceStatusOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminUpdateDeviceStatus(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminUpdateDeviceStatusAsync(const AdminUpdateDeviceStatusRequest& request, const AdminUpdateDeviceStatusResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminUpdateDeviceStatus(request), context);
    } );
}

AdminUpdateUserAttributesOutcome CognitoIdentityProviderClient::AdminUpdateUserAttributes(const AdminUpdateUserAttributesRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminUpdateUserAttributesOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminUpdateUserAttributesOutcomeCallable CognitoIdentityProviderClient::AdminUpdateUserAttributesCallable(const AdminUpdateUserAttributesRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminUpdateUserAttributesOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminUpdateUserAttributes(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminUpdateUserAttributesAsync(const AdminUpdateUserAttributesRequest& request, const AdminUpdateUserAttributesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminUpdateUserAttributes(request), context);
    } );
}

AdminUserGlobalSignOutOutcome CognitoIdentityProviderClient::AdminUserGlobalSignOut(const AdminUserGlobalSignOutRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AdminUserGlobalSignOutOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AdminUserGlobalSignOutOutcomeCallable CognitoIdentityProviderClient::AdminUserGlobalSignOutCallable(const AdminUserGlobalSignOutRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AdminUserGlobalSignOutOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AdminUserGlobalSignOut(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AdminUserGlobalSignOutAsync(const AdminUserGlobalSignOutRequest& request, const AdminUserGlobalSignOutResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AdminUserGlobalSignOut(request), context);
    } );
}

AssociateSoftwareTokenOutcome CognitoIdentityProviderClient::AssociateSoftwareToken(const AssociateSoftwareTokenRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return AssociateSoftwareTokenOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

AssociateSoftwareTokenOutcomeCallable CognitoIdentityProviderClient::AssociateSoftwareTokenCallable(const AssociateSoftwareTokenRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< AssociateSoftwareTokenOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->AssociateSoftwareToken(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::AssociateSoftwareTokenAsync(const AssociateSoftwareTokenRequest& request, const AssociateSoftwareTokenResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, AssociateSoftwareToken(request), context);
    } );
}

ChangePasswordOutcome CognitoIdentityProviderClient::ChangePassword(const ChangePasswordRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ChangePasswordOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

ChangePasswordOutcomeCallable CognitoIdentityProviderClient::ChangePasswordCallable(const ChangePasswordRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ChangePasswordOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ChangePassword(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ChangePasswordAsync(const ChangePasswordRequest& request, const ChangePasswordResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ChangePassword(request), context);
    } );
}

ConfirmDeviceOutcome CognitoIdentityProviderClient::ConfirmDevice(const ConfirmDeviceRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ConfirmDeviceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

ConfirmDeviceOutcomeCallable CognitoIdentityProviderClient::ConfirmDeviceCallable(const ConfirmDeviceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ConfirmDeviceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ConfirmDevice(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ConfirmDeviceAsync(const ConfirmDeviceRequest& request, const ConfirmDeviceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ConfirmDevice(request), context);
    } );
}

ConfirmForgotPasswordOutcome CognitoIdentityProviderClient::ConfirmForgotPassword(const ConfirmForgotPasswordRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ConfirmForgotPasswordOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

ConfirmForgotPasswordOutcomeCallable CognitoIdentityProviderClient::ConfirmForgotPasswordCallable(const ConfirmForgotPasswordRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ConfirmForgotPasswordOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ConfirmForgotPassword(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ConfirmForgotPasswordAsync(const ConfirmForgotPasswordRequest& request, const ConfirmForgotPasswordResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ConfirmForgotPassword(request), context);
    } );
}

ConfirmSignUpOutcome CognitoIdentityProviderClient::ConfirmSignUp(const ConfirmSignUpRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ConfirmSignUpOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

ConfirmSignUpOutcomeCallable CognitoIdentityProviderClient::ConfirmSignUpCallable(const ConfirmSignUpRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ConfirmSignUpOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ConfirmSignUp(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ConfirmSignUpAsync(const ConfirmSignUpRequest& request, const ConfirmSignUpResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ConfirmSignUp(request), context);
    } );
}

CreateGroupOutcome CognitoIdentityProviderClient::CreateGroup(const CreateGroupRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return CreateGroupOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

CreateGroupOutcomeCallable CognitoIdentityProviderClient::CreateGroupCallable(const CreateGroupRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< CreateGroupOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->CreateGroup(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::CreateGroupAsync(const CreateGroupRequest& request, const CreateGroupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, CreateGroup(request), context);
    } );
}

CreateIdentityProviderOutcome CognitoIdentityProviderClient::CreateIdentityProvider(const CreateIdentityProviderRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return CreateIdentityProviderOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

CreateIdentityProviderOutcomeCallable CognitoIdentityProviderClient::CreateIdentityProviderCallable(const CreateIdentityProviderRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< CreateIdentityProviderOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->CreateIdentityProvider(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::CreateIdentityProviderAsync(const CreateIdentityProviderRequest& request, const CreateIdentityProviderResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, CreateIdentityProvider(request), context);
    } );
}

CreateResourceServerOutcome CognitoIdentityProviderClient::CreateResourceServer(const CreateResourceServerRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return CreateResourceServerOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

CreateResourceServerOutcomeCallable CognitoIdentityProviderClient::CreateResourceServerCallable(const CreateResourceServerRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< CreateResourceServerOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->CreateResourceServer(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::CreateResourceServerAsync(const CreateResourceServerRequest& request, const CreateResourceServerResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, CreateResourceServer(request), context);
    } );
}

CreateUserImportJobOutcome CognitoIdentityProviderClient::CreateUserImportJob(const CreateUserImportJobRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return CreateUserImportJobOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

CreateUserImportJobOutcomeCallable CognitoIdentityProviderClient::CreateUserImportJobCallable(const CreateUserImportJobRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< CreateUserImportJobOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->CreateUserImportJob(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::CreateUserImportJobAsync(const CreateUserImportJobRequest& request, const CreateUserImportJobResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, CreateUserImportJob(request), context);
    } );
}

CreateUserPoolOutcome CognitoIdentityProviderClient::CreateUserPool(const CreateUserPoolRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return CreateUserPoolOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

CreateUserPoolOutcomeCallable CognitoIdentityProviderClient::CreateUserPoolCallable(const CreateUserPoolRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< CreateUserPoolOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->CreateUserPool(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::CreateUserPoolAsync(const CreateUserPoolRequest& request, const CreateUserPoolResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, CreateUserPool(request), context);
    } );
}

CreateUserPoolClientOutcome CognitoIdentityProviderClient::CreateUserPoolClient(const CreateUserPoolClientRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return CreateUserPoolClientOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

CreateUserPoolClientOutcomeCallable CognitoIdentityProviderClient::CreateUserPoolClientCallable(const CreateUserPoolClientRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< CreateUserPoolClientOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->CreateUserPoolClient(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::CreateUserPoolClientAsync(const CreateUserPoolClientRequest& request, const CreateUserPoolClientResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, CreateUserPoolClient(request), context);
    } );
}

CreateUserPoolDomainOutcome CognitoIdentityProviderClient::CreateUserPoolDomain(const CreateUserPoolDomainRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return CreateUserPoolDomainOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

CreateUserPoolDomainOutcomeCallable CognitoIdentityProviderClient::CreateUserPoolDomainCallable(const CreateUserPoolDomainRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< CreateUserPoolDomainOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->CreateUserPoolDomain(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::CreateUserPoolDomainAsync(const CreateUserPoolDomainRequest& request, const CreateUserPoolDomainResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, CreateUserPoolDomain(request), context);
    } );
}

DeleteGroupOutcome CognitoIdentityProviderClient::DeleteGroup(const DeleteGroupRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DeleteGroupOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DeleteGroupOutcomeCallable CognitoIdentityProviderClient::DeleteGroupCallable(const DeleteGroupRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DeleteGroupOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DeleteGroup(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DeleteGroupAsync(const DeleteGroupRequest& request, const DeleteGroupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DeleteGroup(request), context);
    } );
}

DeleteIdentityProviderOutcome CognitoIdentityProviderClient::DeleteIdentityProvider(const DeleteIdentityProviderRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DeleteIdentityProviderOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DeleteIdentityProviderOutcomeCallable CognitoIdentityProviderClient::DeleteIdentityProviderCallable(const DeleteIdentityProviderRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DeleteIdentityProviderOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DeleteIdentityProvider(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DeleteIdentityProviderAsync(const DeleteIdentityProviderRequest& request, const DeleteIdentityProviderResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DeleteIdentityProvider(request), context);
    } );
}

DeleteResourceServerOutcome CognitoIdentityProviderClient::DeleteResourceServer(const DeleteResourceServerRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DeleteResourceServerOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DeleteResourceServerOutcomeCallable CognitoIdentityProviderClient::DeleteResourceServerCallable(const DeleteResourceServerRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DeleteResourceServerOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DeleteResourceServer(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DeleteResourceServerAsync(const DeleteResourceServerRequest& request, const DeleteResourceServerResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DeleteResourceServer(request), context);
    } );
}

DeleteUserOutcome CognitoIdentityProviderClient::DeleteUser(const DeleteUserRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DeleteUserOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

DeleteUserOutcomeCallable CognitoIdentityProviderClient::DeleteUserCallable(const DeleteUserRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DeleteUserOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DeleteUser(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DeleteUserAsync(const DeleteUserRequest& request, const DeleteUserResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DeleteUser(request), context);
    } );
}

DeleteUserAttributesOutcome CognitoIdentityProviderClient::DeleteUserAttributes(const DeleteUserAttributesRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DeleteUserAttributesOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

DeleteUserAttributesOutcomeCallable CognitoIdentityProviderClient::DeleteUserAttributesCallable(const DeleteUserAttributesRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DeleteUserAttributesOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DeleteUserAttributes(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DeleteUserAttributesAsync(const DeleteUserAttributesRequest& request, const DeleteUserAttributesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DeleteUserAttributes(request), context);
    } );
}

DeleteUserPoolOutcome CognitoIdentityProviderClient::DeleteUserPool(const DeleteUserPoolRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DeleteUserPoolOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DeleteUserPoolOutcomeCallable CognitoIdentityProviderClient::DeleteUserPoolCallable(const DeleteUserPoolRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DeleteUserPoolOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DeleteUserPool(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DeleteUserPoolAsync(const DeleteUserPoolRequest& request, const DeleteUserPoolResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DeleteUserPool(request), context);
    } );
}

DeleteUserPoolClientOutcome CognitoIdentityProviderClient::DeleteUserPoolClient(const DeleteUserPoolClientRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DeleteUserPoolClientOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DeleteUserPoolClientOutcomeCallable CognitoIdentityProviderClient::DeleteUserPoolClientCallable(const DeleteUserPoolClientRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DeleteUserPoolClientOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DeleteUserPoolClient(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DeleteUserPoolClientAsync(const DeleteUserPoolClientRequest& request, const DeleteUserPoolClientResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DeleteUserPoolClient(request), context);
    } );
}

DeleteUserPoolDomainOutcome CognitoIdentityProviderClient::DeleteUserPoolDomain(const DeleteUserPoolDomainRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DeleteUserPoolDomainOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DeleteUserPoolDomainOutcomeCallable CognitoIdentityProviderClient::DeleteUserPoolDomainCallable(const DeleteUserPoolDomainRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DeleteUserPoolDomainOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DeleteUserPoolDomain(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DeleteUserPoolDomainAsync(const DeleteUserPoolDomainRequest& request, const DeleteUserPoolDomainResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DeleteUserPoolDomain(request), context);
    } );
}

DescribeIdentityProviderOutcome CognitoIdentityProviderClient::DescribeIdentityProvider(const DescribeIdentityProviderRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DescribeIdentityProviderOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DescribeIdentityProviderOutcomeCallable CognitoIdentityProviderClient::DescribeIdentityProviderCallable(const DescribeIdentityProviderRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DescribeIdentityProviderOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DescribeIdentityProvider(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DescribeIdentityProviderAsync(const DescribeIdentityProviderRequest& request, const DescribeIdentityProviderResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DescribeIdentityProvider(request), context);
    } );
}

DescribeResourceServerOutcome CognitoIdentityProviderClient::DescribeResourceServer(const DescribeResourceServerRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DescribeResourceServerOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DescribeResourceServerOutcomeCallable CognitoIdentityProviderClient::DescribeResourceServerCallable(const DescribeResourceServerRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DescribeResourceServerOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DescribeResourceServer(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DescribeResourceServerAsync(const DescribeResourceServerRequest& request, const DescribeResourceServerResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DescribeResourceServer(request), context);
    } );
}

DescribeRiskConfigurationOutcome CognitoIdentityProviderClient::DescribeRiskConfiguration(const DescribeRiskConfigurationRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DescribeRiskConfigurationOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DescribeRiskConfigurationOutcomeCallable CognitoIdentityProviderClient::DescribeRiskConfigurationCallable(const DescribeRiskConfigurationRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DescribeRiskConfigurationOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DescribeRiskConfiguration(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DescribeRiskConfigurationAsync(const DescribeRiskConfigurationRequest& request, const DescribeRiskConfigurationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DescribeRiskConfiguration(request), context);
    } );
}

DescribeUserImportJobOutcome CognitoIdentityProviderClient::DescribeUserImportJob(const DescribeUserImportJobRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DescribeUserImportJobOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DescribeUserImportJobOutcomeCallable CognitoIdentityProviderClient::DescribeUserImportJobCallable(const DescribeUserImportJobRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DescribeUserImportJobOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DescribeUserImportJob(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DescribeUserImportJobAsync(const DescribeUserImportJobRequest& request, const DescribeUserImportJobResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DescribeUserImportJob(request), context);
    } );
}

DescribeUserPoolOutcome CognitoIdentityProviderClient::DescribeUserPool(const DescribeUserPoolRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DescribeUserPoolOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DescribeUserPoolOutcomeCallable CognitoIdentityProviderClient::DescribeUserPoolCallable(const DescribeUserPoolRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DescribeUserPoolOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DescribeUserPool(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DescribeUserPoolAsync(const DescribeUserPoolRequest& request, const DescribeUserPoolResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DescribeUserPool(request), context);
    } );
}

DescribeUserPoolClientOutcome CognitoIdentityProviderClient::DescribeUserPoolClient(const DescribeUserPoolClientRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DescribeUserPoolClientOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DescribeUserPoolClientOutcomeCallable CognitoIdentityProviderClient::DescribeUserPoolClientCallable(const DescribeUserPoolClientRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DescribeUserPoolClientOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DescribeUserPoolClient(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DescribeUserPoolClientAsync(const DescribeUserPoolClientRequest& request, const DescribeUserPoolClientResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DescribeUserPoolClient(request), context);
    } );
}

DescribeUserPoolDomainOutcome CognitoIdentityProviderClient::DescribeUserPoolDomain(const DescribeUserPoolDomainRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return DescribeUserPoolDomainOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

DescribeUserPoolDomainOutcomeCallable CognitoIdentityProviderClient::DescribeUserPoolDomainCallable(const DescribeUserPoolDomainRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DescribeUserPoolDomainOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DescribeUserPoolDomain(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::DescribeUserPoolDomainAsync(const DescribeUserPoolDomainRequest& request, const DescribeUserPoolDomainResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, DescribeUserPoolDomain(request), context);
    } );
}

ForgetDeviceOutcome CognitoIdentityProviderClient::ForgetDevice(const ForgetDeviceRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ForgetDeviceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

ForgetDeviceOutcomeCallable CognitoIdentityProviderClient::ForgetDeviceCallable(const ForgetDeviceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ForgetDeviceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ForgetDevice(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ForgetDeviceAsync(const ForgetDeviceRequest& request, const ForgetDeviceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ForgetDevice(request), context);
    } );
}

ForgotPasswordOutcome CognitoIdentityProviderClient::ForgotPassword(const ForgotPasswordRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ForgotPasswordOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

ForgotPasswordOutcomeCallable CognitoIdentityProviderClient::ForgotPasswordCallable(const ForgotPasswordRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ForgotPasswordOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ForgotPassword(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ForgotPasswordAsync(const ForgotPasswordRequest& request, const ForgotPasswordResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ForgotPassword(request), context);
    } );
}

GetCSVHeaderOutcome CognitoIdentityProviderClient::GetCSVHeader(const GetCSVHeaderRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return GetCSVHeaderOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

GetCSVHeaderOutcomeCallable CognitoIdentityProviderClient::GetCSVHeaderCallable(const GetCSVHeaderRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< GetCSVHeaderOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->GetCSVHeader(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::GetCSVHeaderAsync(const GetCSVHeaderRequest& request, const GetCSVHeaderResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, GetCSVHeader(request), context);
    } );
}

GetDeviceOutcome CognitoIdentityProviderClient::GetDevice(const GetDeviceRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return GetDeviceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

GetDeviceOutcomeCallable CognitoIdentityProviderClient::GetDeviceCallable(const GetDeviceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< GetDeviceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->GetDevice(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::GetDeviceAsync(const GetDeviceRequest& request, const GetDeviceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, GetDevice(request), context);
    } );
}

GetGroupOutcome CognitoIdentityProviderClient::GetGroup(const GetGroupRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return GetGroupOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

GetGroupOutcomeCallable CognitoIdentityProviderClient::GetGroupCallable(const GetGroupRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< GetGroupOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->GetGroup(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::GetGroupAsync(const GetGroupRequest& request, const GetGroupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, GetGroup(request), context);
    } );
}

GetIdentityProviderByIdentifierOutcome CognitoIdentityProviderClient::GetIdentityProviderByIdentifier(const GetIdentityProviderByIdentifierRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return GetIdentityProviderByIdentifierOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

GetIdentityProviderByIdentifierOutcomeCallable CognitoIdentityProviderClient::GetIdentityProviderByIdentifierCallable(const GetIdentityProviderByIdentifierRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< GetIdentityProviderByIdentifierOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->GetIdentityProviderByIdentifier(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::GetIdentityProviderByIdentifierAsync(const GetIdentityProviderByIdentifierRequest& request, const GetIdentityProviderByIdentifierResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, GetIdentityProviderByIdentifier(request), context);
    } );
}

GetSigningCertificateOutcome CognitoIdentityProviderClient::GetSigningCertificate(const GetSigningCertificateRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return GetSigningCertificateOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

GetSigningCertificateOutcomeCallable CognitoIdentityProviderClient::GetSigningCertificateCallable(const GetSigningCertificateRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< GetSigningCertificateOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->GetSigningCertificate(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::GetSigningCertificateAsync(const GetSigningCertificateRequest& request, const GetSigningCertificateResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, GetSigningCertificate(request), context);
    } );
}

GetUICustomizationOutcome CognitoIdentityProviderClient::GetUICustomization(const GetUICustomizationRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return GetUICustomizationOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

GetUICustomizationOutcomeCallable CognitoIdentityProviderClient::GetUICustomizationCallable(const GetUICustomizationRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< GetUICustomizationOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->GetUICustomization(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::GetUICustomizationAsync(const GetUICustomizationRequest& request, const GetUICustomizationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, GetUICustomization(request), context);
    } );
}

GetUserOutcome CognitoIdentityProviderClient::GetUser(const GetUserRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return GetUserOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

GetUserOutcomeCallable CognitoIdentityProviderClient::GetUserCallable(const GetUserRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< GetUserOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->GetUser(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::GetUserAsync(const GetUserRequest& request, const GetUserResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, GetUser(request), context);
    } );
}

GetUserAttributeVerificationCodeOutcome CognitoIdentityProviderClient::GetUserAttributeVerificationCode(const GetUserAttributeVerificationCodeRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return GetUserAttributeVerificationCodeOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

GetUserAttributeVerificationCodeOutcomeCallable CognitoIdentityProviderClient::GetUserAttributeVerificationCodeCallable(const GetUserAttributeVerificationCodeRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< GetUserAttributeVerificationCodeOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->GetUserAttributeVerificationCode(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::GetUserAttributeVerificationCodeAsync(const GetUserAttributeVerificationCodeRequest& request, const GetUserAttributeVerificationCodeResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, GetUserAttributeVerificationCode(request), context);
    } );
}

GetUserPoolMfaConfigOutcome CognitoIdentityProviderClient::GetUserPoolMfaConfig(const GetUserPoolMfaConfigRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return GetUserPoolMfaConfigOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

GetUserPoolMfaConfigOutcomeCallable CognitoIdentityProviderClient::GetUserPoolMfaConfigCallable(const GetUserPoolMfaConfigRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< GetUserPoolMfaConfigOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->GetUserPoolMfaConfig(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::GetUserPoolMfaConfigAsync(const GetUserPoolMfaConfigRequest& request, const GetUserPoolMfaConfigResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, GetUserPoolMfaConfig(request), context);
    } );
}

GlobalSignOutOutcome CognitoIdentityProviderClient::GlobalSignOut(const GlobalSignOutRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return GlobalSignOutOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

GlobalSignOutOutcomeCallable CognitoIdentityProviderClient::GlobalSignOutCallable(const GlobalSignOutRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< GlobalSignOutOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->GlobalSignOut(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::GlobalSignOutAsync(const GlobalSignOutRequest& request, const GlobalSignOutResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, GlobalSignOut(request), context);
    } );
}

InitiateAuthOutcome CognitoIdentityProviderClient::InitiateAuth(const InitiateAuthRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return InitiateAuthOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

InitiateAuthOutcomeCallable CognitoIdentityProviderClient::InitiateAuthCallable(const InitiateAuthRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< InitiateAuthOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->InitiateAuth(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::InitiateAuthAsync(const InitiateAuthRequest& request, const InitiateAuthResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, InitiateAuth(request), context);
    } );
}

ListDevicesOutcome CognitoIdentityProviderClient::ListDevices(const ListDevicesRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ListDevicesOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

ListDevicesOutcomeCallable CognitoIdentityProviderClient::ListDevicesCallable(const ListDevicesRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListDevicesOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListDevices(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ListDevicesAsync(const ListDevicesRequest& request, const ListDevicesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ListDevices(request), context);
    } );
}

ListGroupsOutcome CognitoIdentityProviderClient::ListGroups(const ListGroupsRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ListGroupsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

ListGroupsOutcomeCallable CognitoIdentityProviderClient::ListGroupsCallable(const ListGroupsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListGroupsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListGroups(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ListGroupsAsync(const ListGroupsRequest& request, const ListGroupsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ListGroups(request), context);
    } );
}

ListIdentityProvidersOutcome CognitoIdentityProviderClient::ListIdentityProviders(const ListIdentityProvidersRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ListIdentityProvidersOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

ListIdentityProvidersOutcomeCallable CognitoIdentityProviderClient::ListIdentityProvidersCallable(const ListIdentityProvidersRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListIdentityProvidersOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListIdentityProviders(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ListIdentityProvidersAsync(const ListIdentityProvidersRequest& request, const ListIdentityProvidersResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ListIdentityProviders(request), context);
    } );
}

ListResourceServersOutcome CognitoIdentityProviderClient::ListResourceServers(const ListResourceServersRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ListResourceServersOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

ListResourceServersOutcomeCallable CognitoIdentityProviderClient::ListResourceServersCallable(const ListResourceServersRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListResourceServersOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListResourceServers(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ListResourceServersAsync(const ListResourceServersRequest& request, const ListResourceServersResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ListResourceServers(request), context);
    } );
}

ListTagsForResourceOutcome CognitoIdentityProviderClient::ListTagsForResource(const ListTagsForResourceRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ListTagsForResourceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

ListTagsForResourceOutcomeCallable CognitoIdentityProviderClient::ListTagsForResourceCallable(const ListTagsForResourceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListTagsForResourceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListTagsForResource(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ListTagsForResourceAsync(const ListTagsForResourceRequest& request, const ListTagsForResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ListTagsForResource(request), context);
    } );
}

ListUserImportJobsOutcome CognitoIdentityProviderClient::ListUserImportJobs(const ListUserImportJobsRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ListUserImportJobsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

ListUserImportJobsOutcomeCallable CognitoIdentityProviderClient::ListUserImportJobsCallable(const ListUserImportJobsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListUserImportJobsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListUserImportJobs(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ListUserImportJobsAsync(const ListUserImportJobsRequest& request, const ListUserImportJobsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ListUserImportJobs(request), context);
    } );
}

ListUserPoolClientsOutcome CognitoIdentityProviderClient::ListUserPoolClients(const ListUserPoolClientsRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ListUserPoolClientsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

ListUserPoolClientsOutcomeCallable CognitoIdentityProviderClient::ListUserPoolClientsCallable(const ListUserPoolClientsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListUserPoolClientsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListUserPoolClients(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ListUserPoolClientsAsync(const ListUserPoolClientsRequest& request, const ListUserPoolClientsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ListUserPoolClients(request), context);
    } );
}

ListUserPoolsOutcome CognitoIdentityProviderClient::ListUserPools(const ListUserPoolsRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ListUserPoolsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

ListUserPoolsOutcomeCallable CognitoIdentityProviderClient::ListUserPoolsCallable(const ListUserPoolsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListUserPoolsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListUserPools(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ListUserPoolsAsync(const ListUserPoolsRequest& request, const ListUserPoolsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ListUserPools(request), context);
    } );
}

ListUsersOutcome CognitoIdentityProviderClient::ListUsers(const ListUsersRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ListUsersOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

ListUsersOutcomeCallable CognitoIdentityProviderClient::ListUsersCallable(const ListUsersRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListUsersOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListUsers(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ListUsersAsync(const ListUsersRequest& request, const ListUsersResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ListUsers(request), context);
    } );
}

ListUsersInGroupOutcome CognitoIdentityProviderClient::ListUsersInGroup(const ListUsersInGroupRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ListUsersInGroupOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

ListUsersInGroupOutcomeCallable CognitoIdentityProviderClient::ListUsersInGroupCallable(const ListUsersInGroupRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListUsersInGroupOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListUsersInGroup(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ListUsersInGroupAsync(const ListUsersInGroupRequest& request, const ListUsersInGroupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ListUsersInGroup(request), context);
    } );
}

ResendConfirmationCodeOutcome CognitoIdentityProviderClient::ResendConfirmationCode(const ResendConfirmationCodeRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return ResendConfirmationCodeOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

ResendConfirmationCodeOutcomeCallable CognitoIdentityProviderClient::ResendConfirmationCodeCallable(const ResendConfirmationCodeRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ResendConfirmationCodeOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ResendConfirmationCode(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::ResendConfirmationCodeAsync(const ResendConfirmationCodeRequest& request, const ResendConfirmationCodeResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, ResendConfirmationCode(request), context);
    } );
}

RespondToAuthChallengeOutcome CognitoIdentityProviderClient::RespondToAuthChallenge(const RespondToAuthChallengeRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return RespondToAuthChallengeOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

RespondToAuthChallengeOutcomeCallable CognitoIdentityProviderClient::RespondToAuthChallengeCallable(const RespondToAuthChallengeRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< RespondToAuthChallengeOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->RespondToAuthChallenge(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::RespondToAuthChallengeAsync(const RespondToAuthChallengeRequest& request, const RespondToAuthChallengeResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, RespondToAuthChallenge(request), context);
    } );
}

RevokeTokenOutcome CognitoIdentityProviderClient::RevokeToken(const RevokeTokenRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return RevokeTokenOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

RevokeTokenOutcomeCallable CognitoIdentityProviderClient::RevokeTokenCallable(const RevokeTokenRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< RevokeTokenOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->RevokeToken(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::RevokeTokenAsync(const RevokeTokenRequest& request, const RevokeTokenResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, RevokeToken(request), context);
    } );
}

SetRiskConfigurationOutcome CognitoIdentityProviderClient::SetRiskConfiguration(const SetRiskConfigurationRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return SetRiskConfigurationOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

SetRiskConfigurationOutcomeCallable CognitoIdentityProviderClient::SetRiskConfigurationCallable(const SetRiskConfigurationRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< SetRiskConfigurationOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->SetRiskConfiguration(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::SetRiskConfigurationAsync(const SetRiskConfigurationRequest& request, const SetRiskConfigurationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, SetRiskConfiguration(request), context);
    } );
}

SetUICustomizationOutcome CognitoIdentityProviderClient::SetUICustomization(const SetUICustomizationRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return SetUICustomizationOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

SetUICustomizationOutcomeCallable CognitoIdentityProviderClient::SetUICustomizationCallable(const SetUICustomizationRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< SetUICustomizationOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->SetUICustomization(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::SetUICustomizationAsync(const SetUICustomizationRequest& request, const SetUICustomizationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, SetUICustomization(request), context);
    } );
}

SetUserMFAPreferenceOutcome CognitoIdentityProviderClient::SetUserMFAPreference(const SetUserMFAPreferenceRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return SetUserMFAPreferenceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

SetUserMFAPreferenceOutcomeCallable CognitoIdentityProviderClient::SetUserMFAPreferenceCallable(const SetUserMFAPreferenceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< SetUserMFAPreferenceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->SetUserMFAPreference(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::SetUserMFAPreferenceAsync(const SetUserMFAPreferenceRequest& request, const SetUserMFAPreferenceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, SetUserMFAPreference(request), context);
    } );
}

SetUserPoolMfaConfigOutcome CognitoIdentityProviderClient::SetUserPoolMfaConfig(const SetUserPoolMfaConfigRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return SetUserPoolMfaConfigOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

SetUserPoolMfaConfigOutcomeCallable CognitoIdentityProviderClient::SetUserPoolMfaConfigCallable(const SetUserPoolMfaConfigRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< SetUserPoolMfaConfigOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->SetUserPoolMfaConfig(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::SetUserPoolMfaConfigAsync(const SetUserPoolMfaConfigRequest& request, const SetUserPoolMfaConfigResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, SetUserPoolMfaConfig(request), context);
    } );
}

SetUserSettingsOutcome CognitoIdentityProviderClient::SetUserSettings(const SetUserSettingsRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return SetUserSettingsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

SetUserSettingsOutcomeCallable CognitoIdentityProviderClient::SetUserSettingsCallable(const SetUserSettingsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< SetUserSettingsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->SetUserSettings(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::SetUserSettingsAsync(const SetUserSettingsRequest& request, const SetUserSettingsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, SetUserSettings(request), context);
    } );
}

SignUpOutcome CognitoIdentityProviderClient::SignUp(const SignUpRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return SignUpOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

SignUpOutcomeCallable CognitoIdentityProviderClient::SignUpCallable(const SignUpRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< SignUpOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->SignUp(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::SignUpAsync(const SignUpRequest& request, const SignUpResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, SignUp(request), context);
    } );
}

StartUserImportJobOutcome CognitoIdentityProviderClient::StartUserImportJob(const StartUserImportJobRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return StartUserImportJobOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

StartUserImportJobOutcomeCallable CognitoIdentityProviderClient::StartUserImportJobCallable(const StartUserImportJobRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< StartUserImportJobOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->StartUserImportJob(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::StartUserImportJobAsync(const StartUserImportJobRequest& request, const StartUserImportJobResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, StartUserImportJob(request), context);
    } );
}

StopUserImportJobOutcome CognitoIdentityProviderClient::StopUserImportJob(const StopUserImportJobRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return StopUserImportJobOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

StopUserImportJobOutcomeCallable CognitoIdentityProviderClient::StopUserImportJobCallable(const StopUserImportJobRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< StopUserImportJobOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->StopUserImportJob(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::StopUserImportJobAsync(const StopUserImportJobRequest& request, const StopUserImportJobResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, StopUserImportJob(request), context);
    } );
}

TagResourceOutcome CognitoIdentityProviderClient::TagResource(const TagResourceRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return TagResourceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

TagResourceOutcomeCallable CognitoIdentityProviderClient::TagResourceCallable(const TagResourceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< TagResourceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->TagResource(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::TagResourceAsync(const TagResourceRequest& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, TagResource(request), context);
    } );
}

UntagResourceOutcome CognitoIdentityProviderClient::UntagResource(const UntagResourceRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return UntagResourceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

UntagResourceOutcomeCallable CognitoIdentityProviderClient::UntagResourceCallable(const UntagResourceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UntagResourceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UntagResource(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::UntagResourceAsync(const UntagResourceRequest& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, UntagResource(request), context);
    } );
}

UpdateAuthEventFeedbackOutcome CognitoIdentityProviderClient::UpdateAuthEventFeedback(const UpdateAuthEventFeedbackRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return UpdateAuthEventFeedbackOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

UpdateAuthEventFeedbackOutcomeCallable CognitoIdentityProviderClient::UpdateAuthEventFeedbackCallable(const UpdateAuthEventFeedbackRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UpdateAuthEventFeedbackOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UpdateAuthEventFeedback(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::UpdateAuthEventFeedbackAsync(const UpdateAuthEventFeedbackRequest& request, const UpdateAuthEventFeedbackResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, UpdateAuthEventFeedback(request), context);
    } );
}

UpdateDeviceStatusOutcome CognitoIdentityProviderClient::UpdateDeviceStatus(const UpdateDeviceStatusRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return UpdateDeviceStatusOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

UpdateDeviceStatusOutcomeCallable CognitoIdentityProviderClient::UpdateDeviceStatusCallable(const UpdateDeviceStatusRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UpdateDeviceStatusOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UpdateDeviceStatus(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::UpdateDeviceStatusAsync(const UpdateDeviceStatusRequest& request, const UpdateDeviceStatusResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, UpdateDeviceStatus(request), context);
    } );
}

UpdateGroupOutcome CognitoIdentityProviderClient::UpdateGroup(const UpdateGroupRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return UpdateGroupOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

UpdateGroupOutcomeCallable CognitoIdentityProviderClient::UpdateGroupCallable(const UpdateGroupRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UpdateGroupOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UpdateGroup(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::UpdateGroupAsync(const UpdateGroupRequest& request, const UpdateGroupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, UpdateGroup(request), context);
    } );
}

UpdateIdentityProviderOutcome CognitoIdentityProviderClient::UpdateIdentityProvider(const UpdateIdentityProviderRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return UpdateIdentityProviderOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

UpdateIdentityProviderOutcomeCallable CognitoIdentityProviderClient::UpdateIdentityProviderCallable(const UpdateIdentityProviderRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UpdateIdentityProviderOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UpdateIdentityProvider(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::UpdateIdentityProviderAsync(const UpdateIdentityProviderRequest& request, const UpdateIdentityProviderResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, UpdateIdentityProvider(request), context);
    } );
}

UpdateResourceServerOutcome CognitoIdentityProviderClient::UpdateResourceServer(const UpdateResourceServerRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return UpdateResourceServerOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

UpdateResourceServerOutcomeCallable CognitoIdentityProviderClient::UpdateResourceServerCallable(const UpdateResourceServerRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UpdateResourceServerOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UpdateResourceServer(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::UpdateResourceServerAsync(const UpdateResourceServerRequest& request, const UpdateResourceServerResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, UpdateResourceServer(request), context);
    } );
}

UpdateUserAttributesOutcome CognitoIdentityProviderClient::UpdateUserAttributes(const UpdateUserAttributesRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return UpdateUserAttributesOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

UpdateUserAttributesOutcomeCallable CognitoIdentityProviderClient::UpdateUserAttributesCallable(const UpdateUserAttributesRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UpdateUserAttributesOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UpdateUserAttributes(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::UpdateUserAttributesAsync(const UpdateUserAttributesRequest& request, const UpdateUserAttributesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, UpdateUserAttributes(request), context);
    } );
}

UpdateUserPoolOutcome CognitoIdentityProviderClient::UpdateUserPool(const UpdateUserPoolRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return UpdateUserPoolOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

UpdateUserPoolOutcomeCallable CognitoIdentityProviderClient::UpdateUserPoolCallable(const UpdateUserPoolRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UpdateUserPoolOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UpdateUserPool(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::UpdateUserPoolAsync(const UpdateUserPoolRequest& request, const UpdateUserPoolResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, UpdateUserPool(request), context);
    } );
}

UpdateUserPoolClientOutcome CognitoIdentityProviderClient::UpdateUserPoolClient(const UpdateUserPoolClientRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return UpdateUserPoolClientOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

UpdateUserPoolClientOutcomeCallable CognitoIdentityProviderClient::UpdateUserPoolClientCallable(const UpdateUserPoolClientRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UpdateUserPoolClientOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UpdateUserPoolClient(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::UpdateUserPoolClientAsync(const UpdateUserPoolClientRequest& request, const UpdateUserPoolClientResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, UpdateUserPoolClient(request), context);
    } );
}

UpdateUserPoolDomainOutcome CognitoIdentityProviderClient::UpdateUserPoolDomain(const UpdateUserPoolDomainRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return UpdateUserPoolDomainOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

UpdateUserPoolDomainOutcomeCallable CognitoIdentityProviderClient::UpdateUserPoolDomainCallable(const UpdateUserPoolDomainRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UpdateUserPoolDomainOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UpdateUserPoolDomain(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::UpdateUserPoolDomainAsync(const UpdateUserPoolDomainRequest& request, const UpdateUserPoolDomainResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, UpdateUserPoolDomain(request), context);
    } );
}

VerifySoftwareTokenOutcome CognitoIdentityProviderClient::VerifySoftwareToken(const VerifySoftwareTokenRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return VerifySoftwareTokenOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

VerifySoftwareTokenOutcomeCallable CognitoIdentityProviderClient::VerifySoftwareTokenCallable(const VerifySoftwareTokenRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< VerifySoftwareTokenOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->VerifySoftwareToken(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::VerifySoftwareTokenAsync(const VerifySoftwareTokenRequest& request, const VerifySoftwareTokenResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, VerifySoftwareToken(request), context);
    } );
}

VerifyUserAttributeOutcome CognitoIdentityProviderClient::VerifyUserAttribute(const VerifyUserAttributeRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  return VerifyUserAttributeOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::NULL_SIGNER));
}

VerifyUserAttributeOutcomeCallable CognitoIdentityProviderClient::VerifyUserAttributeCallable(const VerifyUserAttributeRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< VerifyUserAttributeOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->VerifyUserAttribute(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void CognitoIdentityProviderClient::VerifyUserAttributeAsync(const VerifyUserAttributeRequest& request, const VerifyUserAttributeResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context]()
    {
      handler(this, request, VerifyUserAttribute(request), context);
    } );
}

