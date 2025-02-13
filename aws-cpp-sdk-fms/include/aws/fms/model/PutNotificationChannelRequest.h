﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/fms/FMS_EXPORTS.h>
#include <aws/fms/FMSRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace FMS
{
namespace Model
{

  /**
   */
  class AWS_FMS_API PutNotificationChannelRequest : public FMSRequest
  {
  public:
    PutNotificationChannelRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "PutNotificationChannel"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic that collects notifications
     * from Firewall Manager.</p>
     */
    inline const Aws::String& GetSnsTopicArn() const{ return m_snsTopicArn; }

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic that collects notifications
     * from Firewall Manager.</p>
     */
    inline bool SnsTopicArnHasBeenSet() const { return m_snsTopicArnHasBeenSet; }

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic that collects notifications
     * from Firewall Manager.</p>
     */
    inline void SetSnsTopicArn(const Aws::String& value) { m_snsTopicArnHasBeenSet = true; m_snsTopicArn = value; }

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic that collects notifications
     * from Firewall Manager.</p>
     */
    inline void SetSnsTopicArn(Aws::String&& value) { m_snsTopicArnHasBeenSet = true; m_snsTopicArn = std::move(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic that collects notifications
     * from Firewall Manager.</p>
     */
    inline void SetSnsTopicArn(const char* value) { m_snsTopicArnHasBeenSet = true; m_snsTopicArn.assign(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic that collects notifications
     * from Firewall Manager.</p>
     */
    inline PutNotificationChannelRequest& WithSnsTopicArn(const Aws::String& value) { SetSnsTopicArn(value); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic that collects notifications
     * from Firewall Manager.</p>
     */
    inline PutNotificationChannelRequest& WithSnsTopicArn(Aws::String&& value) { SetSnsTopicArn(std::move(value)); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic that collects notifications
     * from Firewall Manager.</p>
     */
    inline PutNotificationChannelRequest& WithSnsTopicArn(const char* value) { SetSnsTopicArn(value); return *this;}


    /**
     * <p>The Amazon Resource Name (ARN) of the IAM role that allows Amazon SNS to
     * record Firewall Manager activity. </p>
     */
    inline const Aws::String& GetSnsRoleName() const{ return m_snsRoleName; }

    /**
     * <p>The Amazon Resource Name (ARN) of the IAM role that allows Amazon SNS to
     * record Firewall Manager activity. </p>
     */
    inline bool SnsRoleNameHasBeenSet() const { return m_snsRoleNameHasBeenSet; }

    /**
     * <p>The Amazon Resource Name (ARN) of the IAM role that allows Amazon SNS to
     * record Firewall Manager activity. </p>
     */
    inline void SetSnsRoleName(const Aws::String& value) { m_snsRoleNameHasBeenSet = true; m_snsRoleName = value; }

    /**
     * <p>The Amazon Resource Name (ARN) of the IAM role that allows Amazon SNS to
     * record Firewall Manager activity. </p>
     */
    inline void SetSnsRoleName(Aws::String&& value) { m_snsRoleNameHasBeenSet = true; m_snsRoleName = std::move(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the IAM role that allows Amazon SNS to
     * record Firewall Manager activity. </p>
     */
    inline void SetSnsRoleName(const char* value) { m_snsRoleNameHasBeenSet = true; m_snsRoleName.assign(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the IAM role that allows Amazon SNS to
     * record Firewall Manager activity. </p>
     */
    inline PutNotificationChannelRequest& WithSnsRoleName(const Aws::String& value) { SetSnsRoleName(value); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the IAM role that allows Amazon SNS to
     * record Firewall Manager activity. </p>
     */
    inline PutNotificationChannelRequest& WithSnsRoleName(Aws::String&& value) { SetSnsRoleName(std::move(value)); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the IAM role that allows Amazon SNS to
     * record Firewall Manager activity. </p>
     */
    inline PutNotificationChannelRequest& WithSnsRoleName(const char* value) { SetSnsRoleName(value); return *this;}

  private:

    Aws::String m_snsTopicArn;
    bool m_snsTopicArnHasBeenSet = false;

    Aws::String m_snsRoleName;
    bool m_snsRoleNameHasBeenSet = false;
  };

} // namespace Model
} // namespace FMS
} // namespace Aws
