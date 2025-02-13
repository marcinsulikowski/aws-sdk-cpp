﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/lightsail/Lightsail_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/DateTime.h>
#include <aws/lightsail/model/ResourceLocation.h>
#include <aws/lightsail/model/ResourceType.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/lightsail/model/LoadBalancerTlsCertificateStatus.h>
#include <aws/lightsail/model/LoadBalancerTlsCertificateFailureReason.h>
#include <aws/lightsail/model/LoadBalancerTlsCertificateRenewalSummary.h>
#include <aws/lightsail/model/LoadBalancerTlsCertificateRevocationReason.h>
#include <aws/lightsail/model/Tag.h>
#include <aws/lightsail/model/LoadBalancerTlsCertificateDomainValidationRecord.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace Lightsail
{
namespace Model
{

  /**
   * <p>Describes a load balancer SSL/TLS certificate.</p> <p>TLS is just an updated,
   * more secure version of Secure Socket Layer (SSL).</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/lightsail-2016-11-28/LoadBalancerTlsCertificate">AWS
   * API Reference</a></p>
   */
  class AWS_LIGHTSAIL_API LoadBalancerTlsCertificate
  {
  public:
    LoadBalancerTlsCertificate();
    LoadBalancerTlsCertificate(Aws::Utils::Json::JsonView jsonValue);
    LoadBalancerTlsCertificate& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The name of the SSL/TLS certificate (e.g., <code>my-certificate</code>).</p>
     */
    inline const Aws::String& GetName() const{ return m_name; }

    /**
     * <p>The name of the SSL/TLS certificate (e.g., <code>my-certificate</code>).</p>
     */
    inline bool NameHasBeenSet() const { return m_nameHasBeenSet; }

    /**
     * <p>The name of the SSL/TLS certificate (e.g., <code>my-certificate</code>).</p>
     */
    inline void SetName(const Aws::String& value) { m_nameHasBeenSet = true; m_name = value; }

    /**
     * <p>The name of the SSL/TLS certificate (e.g., <code>my-certificate</code>).</p>
     */
    inline void SetName(Aws::String&& value) { m_nameHasBeenSet = true; m_name = std::move(value); }

    /**
     * <p>The name of the SSL/TLS certificate (e.g., <code>my-certificate</code>).</p>
     */
    inline void SetName(const char* value) { m_nameHasBeenSet = true; m_name.assign(value); }

    /**
     * <p>The name of the SSL/TLS certificate (e.g., <code>my-certificate</code>).</p>
     */
    inline LoadBalancerTlsCertificate& WithName(const Aws::String& value) { SetName(value); return *this;}

    /**
     * <p>The name of the SSL/TLS certificate (e.g., <code>my-certificate</code>).</p>
     */
    inline LoadBalancerTlsCertificate& WithName(Aws::String&& value) { SetName(std::move(value)); return *this;}

    /**
     * <p>The name of the SSL/TLS certificate (e.g., <code>my-certificate</code>).</p>
     */
    inline LoadBalancerTlsCertificate& WithName(const char* value) { SetName(value); return *this;}


    /**
     * <p>The Amazon Resource Name (ARN) of the SSL/TLS certificate.</p>
     */
    inline const Aws::String& GetArn() const{ return m_arn; }

    /**
     * <p>The Amazon Resource Name (ARN) of the SSL/TLS certificate.</p>
     */
    inline bool ArnHasBeenSet() const { return m_arnHasBeenSet; }

    /**
     * <p>The Amazon Resource Name (ARN) of the SSL/TLS certificate.</p>
     */
    inline void SetArn(const Aws::String& value) { m_arnHasBeenSet = true; m_arn = value; }

    /**
     * <p>The Amazon Resource Name (ARN) of the SSL/TLS certificate.</p>
     */
    inline void SetArn(Aws::String&& value) { m_arnHasBeenSet = true; m_arn = std::move(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the SSL/TLS certificate.</p>
     */
    inline void SetArn(const char* value) { m_arnHasBeenSet = true; m_arn.assign(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the SSL/TLS certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithArn(const Aws::String& value) { SetArn(value); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the SSL/TLS certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithArn(Aws::String&& value) { SetArn(std::move(value)); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the SSL/TLS certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithArn(const char* value) { SetArn(value); return *this;}


    /**
     * <p>The support code. Include this code in your email to support when you have
     * questions about your Lightsail load balancer or SSL/TLS certificate. This code
     * enables our support team to look up your Lightsail information more easily.</p>
     */
    inline const Aws::String& GetSupportCode() const{ return m_supportCode; }

    /**
     * <p>The support code. Include this code in your email to support when you have
     * questions about your Lightsail load balancer or SSL/TLS certificate. This code
     * enables our support team to look up your Lightsail information more easily.</p>
     */
    inline bool SupportCodeHasBeenSet() const { return m_supportCodeHasBeenSet; }

    /**
     * <p>The support code. Include this code in your email to support when you have
     * questions about your Lightsail load balancer or SSL/TLS certificate. This code
     * enables our support team to look up your Lightsail information more easily.</p>
     */
    inline void SetSupportCode(const Aws::String& value) { m_supportCodeHasBeenSet = true; m_supportCode = value; }

    /**
     * <p>The support code. Include this code in your email to support when you have
     * questions about your Lightsail load balancer or SSL/TLS certificate. This code
     * enables our support team to look up your Lightsail information more easily.</p>
     */
    inline void SetSupportCode(Aws::String&& value) { m_supportCodeHasBeenSet = true; m_supportCode = std::move(value); }

    /**
     * <p>The support code. Include this code in your email to support when you have
     * questions about your Lightsail load balancer or SSL/TLS certificate. This code
     * enables our support team to look up your Lightsail information more easily.</p>
     */
    inline void SetSupportCode(const char* value) { m_supportCodeHasBeenSet = true; m_supportCode.assign(value); }

    /**
     * <p>The support code. Include this code in your email to support when you have
     * questions about your Lightsail load balancer or SSL/TLS certificate. This code
     * enables our support team to look up your Lightsail information more easily.</p>
     */
    inline LoadBalancerTlsCertificate& WithSupportCode(const Aws::String& value) { SetSupportCode(value); return *this;}

    /**
     * <p>The support code. Include this code in your email to support when you have
     * questions about your Lightsail load balancer or SSL/TLS certificate. This code
     * enables our support team to look up your Lightsail information more easily.</p>
     */
    inline LoadBalancerTlsCertificate& WithSupportCode(Aws::String&& value) { SetSupportCode(std::move(value)); return *this;}

    /**
     * <p>The support code. Include this code in your email to support when you have
     * questions about your Lightsail load balancer or SSL/TLS certificate. This code
     * enables our support team to look up your Lightsail information more easily.</p>
     */
    inline LoadBalancerTlsCertificate& WithSupportCode(const char* value) { SetSupportCode(value); return *this;}


    /**
     * <p>The time when you created your SSL/TLS certificate.</p>
     */
    inline const Aws::Utils::DateTime& GetCreatedAt() const{ return m_createdAt; }

    /**
     * <p>The time when you created your SSL/TLS certificate.</p>
     */
    inline bool CreatedAtHasBeenSet() const { return m_createdAtHasBeenSet; }

    /**
     * <p>The time when you created your SSL/TLS certificate.</p>
     */
    inline void SetCreatedAt(const Aws::Utils::DateTime& value) { m_createdAtHasBeenSet = true; m_createdAt = value; }

    /**
     * <p>The time when you created your SSL/TLS certificate.</p>
     */
    inline void SetCreatedAt(Aws::Utils::DateTime&& value) { m_createdAtHasBeenSet = true; m_createdAt = std::move(value); }

    /**
     * <p>The time when you created your SSL/TLS certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithCreatedAt(const Aws::Utils::DateTime& value) { SetCreatedAt(value); return *this;}

    /**
     * <p>The time when you created your SSL/TLS certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithCreatedAt(Aws::Utils::DateTime&& value) { SetCreatedAt(std::move(value)); return *this;}


    /**
     * <p>The AWS Region and Availability Zone where you created your certificate.</p>
     */
    inline const ResourceLocation& GetLocation() const{ return m_location; }

    /**
     * <p>The AWS Region and Availability Zone where you created your certificate.</p>
     */
    inline bool LocationHasBeenSet() const { return m_locationHasBeenSet; }

    /**
     * <p>The AWS Region and Availability Zone where you created your certificate.</p>
     */
    inline void SetLocation(const ResourceLocation& value) { m_locationHasBeenSet = true; m_location = value; }

    /**
     * <p>The AWS Region and Availability Zone where you created your certificate.</p>
     */
    inline void SetLocation(ResourceLocation&& value) { m_locationHasBeenSet = true; m_location = std::move(value); }

    /**
     * <p>The AWS Region and Availability Zone where you created your certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithLocation(const ResourceLocation& value) { SetLocation(value); return *this;}

    /**
     * <p>The AWS Region and Availability Zone where you created your certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithLocation(ResourceLocation&& value) { SetLocation(std::move(value)); return *this;}


    /**
     * <p>The resource type (e.g., <code>LoadBalancerTlsCertificate</code>).</p> <ul>
     * <li> <p> <b> <code>Instance</code> </b> - A Lightsail instance (a virtual
     * private server)</p> </li> <li> <p> <b> <code>StaticIp</code> </b> - A static IP
     * address</p> </li> <li> <p> <b> <code>KeyPair</code> </b> - The key pair used to
     * connect to a Lightsail instance</p> </li> <li> <p> <b>
     * <code>InstanceSnapshot</code> </b> - A Lightsail instance snapshot</p> </li>
     * <li> <p> <b> <code>Domain</code> </b> - A DNS zone</p> </li> <li> <p> <b>
     * <code>PeeredVpc</code> </b> - A peered VPC</p> </li> <li> <p> <b>
     * <code>LoadBalancer</code> </b> - A Lightsail load balancer</p> </li> <li> <p>
     * <b> <code>LoadBalancerTlsCertificate</code> </b> - An SSL/TLS certificate
     * associated with a Lightsail load balancer</p> </li> <li> <p> <b>
     * <code>Disk</code> </b> - A Lightsail block storage disk</p> </li> <li> <p> <b>
     * <code>DiskSnapshot</code> </b> - A block storage disk snapshot</p> </li> </ul>
     */
    inline const ResourceType& GetResourceType() const{ return m_resourceType; }

    /**
     * <p>The resource type (e.g., <code>LoadBalancerTlsCertificate</code>).</p> <ul>
     * <li> <p> <b> <code>Instance</code> </b> - A Lightsail instance (a virtual
     * private server)</p> </li> <li> <p> <b> <code>StaticIp</code> </b> - A static IP
     * address</p> </li> <li> <p> <b> <code>KeyPair</code> </b> - The key pair used to
     * connect to a Lightsail instance</p> </li> <li> <p> <b>
     * <code>InstanceSnapshot</code> </b> - A Lightsail instance snapshot</p> </li>
     * <li> <p> <b> <code>Domain</code> </b> - A DNS zone</p> </li> <li> <p> <b>
     * <code>PeeredVpc</code> </b> - A peered VPC</p> </li> <li> <p> <b>
     * <code>LoadBalancer</code> </b> - A Lightsail load balancer</p> </li> <li> <p>
     * <b> <code>LoadBalancerTlsCertificate</code> </b> - An SSL/TLS certificate
     * associated with a Lightsail load balancer</p> </li> <li> <p> <b>
     * <code>Disk</code> </b> - A Lightsail block storage disk</p> </li> <li> <p> <b>
     * <code>DiskSnapshot</code> </b> - A block storage disk snapshot</p> </li> </ul>
     */
    inline bool ResourceTypeHasBeenSet() const { return m_resourceTypeHasBeenSet; }

    /**
     * <p>The resource type (e.g., <code>LoadBalancerTlsCertificate</code>).</p> <ul>
     * <li> <p> <b> <code>Instance</code> </b> - A Lightsail instance (a virtual
     * private server)</p> </li> <li> <p> <b> <code>StaticIp</code> </b> - A static IP
     * address</p> </li> <li> <p> <b> <code>KeyPair</code> </b> - The key pair used to
     * connect to a Lightsail instance</p> </li> <li> <p> <b>
     * <code>InstanceSnapshot</code> </b> - A Lightsail instance snapshot</p> </li>
     * <li> <p> <b> <code>Domain</code> </b> - A DNS zone</p> </li> <li> <p> <b>
     * <code>PeeredVpc</code> </b> - A peered VPC</p> </li> <li> <p> <b>
     * <code>LoadBalancer</code> </b> - A Lightsail load balancer</p> </li> <li> <p>
     * <b> <code>LoadBalancerTlsCertificate</code> </b> - An SSL/TLS certificate
     * associated with a Lightsail load balancer</p> </li> <li> <p> <b>
     * <code>Disk</code> </b> - A Lightsail block storage disk</p> </li> <li> <p> <b>
     * <code>DiskSnapshot</code> </b> - A block storage disk snapshot</p> </li> </ul>
     */
    inline void SetResourceType(const ResourceType& value) { m_resourceTypeHasBeenSet = true; m_resourceType = value; }

    /**
     * <p>The resource type (e.g., <code>LoadBalancerTlsCertificate</code>).</p> <ul>
     * <li> <p> <b> <code>Instance</code> </b> - A Lightsail instance (a virtual
     * private server)</p> </li> <li> <p> <b> <code>StaticIp</code> </b> - A static IP
     * address</p> </li> <li> <p> <b> <code>KeyPair</code> </b> - The key pair used to
     * connect to a Lightsail instance</p> </li> <li> <p> <b>
     * <code>InstanceSnapshot</code> </b> - A Lightsail instance snapshot</p> </li>
     * <li> <p> <b> <code>Domain</code> </b> - A DNS zone</p> </li> <li> <p> <b>
     * <code>PeeredVpc</code> </b> - A peered VPC</p> </li> <li> <p> <b>
     * <code>LoadBalancer</code> </b> - A Lightsail load balancer</p> </li> <li> <p>
     * <b> <code>LoadBalancerTlsCertificate</code> </b> - An SSL/TLS certificate
     * associated with a Lightsail load balancer</p> </li> <li> <p> <b>
     * <code>Disk</code> </b> - A Lightsail block storage disk</p> </li> <li> <p> <b>
     * <code>DiskSnapshot</code> </b> - A block storage disk snapshot</p> </li> </ul>
     */
    inline void SetResourceType(ResourceType&& value) { m_resourceTypeHasBeenSet = true; m_resourceType = std::move(value); }

    /**
     * <p>The resource type (e.g., <code>LoadBalancerTlsCertificate</code>).</p> <ul>
     * <li> <p> <b> <code>Instance</code> </b> - A Lightsail instance (a virtual
     * private server)</p> </li> <li> <p> <b> <code>StaticIp</code> </b> - A static IP
     * address</p> </li> <li> <p> <b> <code>KeyPair</code> </b> - The key pair used to
     * connect to a Lightsail instance</p> </li> <li> <p> <b>
     * <code>InstanceSnapshot</code> </b> - A Lightsail instance snapshot</p> </li>
     * <li> <p> <b> <code>Domain</code> </b> - A DNS zone</p> </li> <li> <p> <b>
     * <code>PeeredVpc</code> </b> - A peered VPC</p> </li> <li> <p> <b>
     * <code>LoadBalancer</code> </b> - A Lightsail load balancer</p> </li> <li> <p>
     * <b> <code>LoadBalancerTlsCertificate</code> </b> - An SSL/TLS certificate
     * associated with a Lightsail load balancer</p> </li> <li> <p> <b>
     * <code>Disk</code> </b> - A Lightsail block storage disk</p> </li> <li> <p> <b>
     * <code>DiskSnapshot</code> </b> - A block storage disk snapshot</p> </li> </ul>
     */
    inline LoadBalancerTlsCertificate& WithResourceType(const ResourceType& value) { SetResourceType(value); return *this;}

    /**
     * <p>The resource type (e.g., <code>LoadBalancerTlsCertificate</code>).</p> <ul>
     * <li> <p> <b> <code>Instance</code> </b> - A Lightsail instance (a virtual
     * private server)</p> </li> <li> <p> <b> <code>StaticIp</code> </b> - A static IP
     * address</p> </li> <li> <p> <b> <code>KeyPair</code> </b> - The key pair used to
     * connect to a Lightsail instance</p> </li> <li> <p> <b>
     * <code>InstanceSnapshot</code> </b> - A Lightsail instance snapshot</p> </li>
     * <li> <p> <b> <code>Domain</code> </b> - A DNS zone</p> </li> <li> <p> <b>
     * <code>PeeredVpc</code> </b> - A peered VPC</p> </li> <li> <p> <b>
     * <code>LoadBalancer</code> </b> - A Lightsail load balancer</p> </li> <li> <p>
     * <b> <code>LoadBalancerTlsCertificate</code> </b> - An SSL/TLS certificate
     * associated with a Lightsail load balancer</p> </li> <li> <p> <b>
     * <code>Disk</code> </b> - A Lightsail block storage disk</p> </li> <li> <p> <b>
     * <code>DiskSnapshot</code> </b> - A block storage disk snapshot</p> </li> </ul>
     */
    inline LoadBalancerTlsCertificate& WithResourceType(ResourceType&& value) { SetResourceType(std::move(value)); return *this;}


    /**
     * <p>The tag keys and optional values for the resource. For more information about
     * tags in Lightsail, see the <a
     * href="https://lightsail.aws.amazon.com/ls/docs/en_us/articles/amazon-lightsail-tags">Amazon
     * Lightsail Developer Guide</a>.</p>
     */
    inline const Aws::Vector<Tag>& GetTags() const{ return m_tags; }

    /**
     * <p>The tag keys and optional values for the resource. For more information about
     * tags in Lightsail, see the <a
     * href="https://lightsail.aws.amazon.com/ls/docs/en_us/articles/amazon-lightsail-tags">Amazon
     * Lightsail Developer Guide</a>.</p>
     */
    inline bool TagsHasBeenSet() const { return m_tagsHasBeenSet; }

    /**
     * <p>The tag keys and optional values for the resource. For more information about
     * tags in Lightsail, see the <a
     * href="https://lightsail.aws.amazon.com/ls/docs/en_us/articles/amazon-lightsail-tags">Amazon
     * Lightsail Developer Guide</a>.</p>
     */
    inline void SetTags(const Aws::Vector<Tag>& value) { m_tagsHasBeenSet = true; m_tags = value; }

    /**
     * <p>The tag keys and optional values for the resource. For more information about
     * tags in Lightsail, see the <a
     * href="https://lightsail.aws.amazon.com/ls/docs/en_us/articles/amazon-lightsail-tags">Amazon
     * Lightsail Developer Guide</a>.</p>
     */
    inline void SetTags(Aws::Vector<Tag>&& value) { m_tagsHasBeenSet = true; m_tags = std::move(value); }

    /**
     * <p>The tag keys and optional values for the resource. For more information about
     * tags in Lightsail, see the <a
     * href="https://lightsail.aws.amazon.com/ls/docs/en_us/articles/amazon-lightsail-tags">Amazon
     * Lightsail Developer Guide</a>.</p>
     */
    inline LoadBalancerTlsCertificate& WithTags(const Aws::Vector<Tag>& value) { SetTags(value); return *this;}

    /**
     * <p>The tag keys and optional values for the resource. For more information about
     * tags in Lightsail, see the <a
     * href="https://lightsail.aws.amazon.com/ls/docs/en_us/articles/amazon-lightsail-tags">Amazon
     * Lightsail Developer Guide</a>.</p>
     */
    inline LoadBalancerTlsCertificate& WithTags(Aws::Vector<Tag>&& value) { SetTags(std::move(value)); return *this;}

    /**
     * <p>The tag keys and optional values for the resource. For more information about
     * tags in Lightsail, see the <a
     * href="https://lightsail.aws.amazon.com/ls/docs/en_us/articles/amazon-lightsail-tags">Amazon
     * Lightsail Developer Guide</a>.</p>
     */
    inline LoadBalancerTlsCertificate& AddTags(const Tag& value) { m_tagsHasBeenSet = true; m_tags.push_back(value); return *this; }

    /**
     * <p>The tag keys and optional values for the resource. For more information about
     * tags in Lightsail, see the <a
     * href="https://lightsail.aws.amazon.com/ls/docs/en_us/articles/amazon-lightsail-tags">Amazon
     * Lightsail Developer Guide</a>.</p>
     */
    inline LoadBalancerTlsCertificate& AddTags(Tag&& value) { m_tagsHasBeenSet = true; m_tags.push_back(std::move(value)); return *this; }


    /**
     * <p>The load balancer name where your SSL/TLS certificate is attached.</p>
     */
    inline const Aws::String& GetLoadBalancerName() const{ return m_loadBalancerName; }

    /**
     * <p>The load balancer name where your SSL/TLS certificate is attached.</p>
     */
    inline bool LoadBalancerNameHasBeenSet() const { return m_loadBalancerNameHasBeenSet; }

    /**
     * <p>The load balancer name where your SSL/TLS certificate is attached.</p>
     */
    inline void SetLoadBalancerName(const Aws::String& value) { m_loadBalancerNameHasBeenSet = true; m_loadBalancerName = value; }

    /**
     * <p>The load balancer name where your SSL/TLS certificate is attached.</p>
     */
    inline void SetLoadBalancerName(Aws::String&& value) { m_loadBalancerNameHasBeenSet = true; m_loadBalancerName = std::move(value); }

    /**
     * <p>The load balancer name where your SSL/TLS certificate is attached.</p>
     */
    inline void SetLoadBalancerName(const char* value) { m_loadBalancerNameHasBeenSet = true; m_loadBalancerName.assign(value); }

    /**
     * <p>The load balancer name where your SSL/TLS certificate is attached.</p>
     */
    inline LoadBalancerTlsCertificate& WithLoadBalancerName(const Aws::String& value) { SetLoadBalancerName(value); return *this;}

    /**
     * <p>The load balancer name where your SSL/TLS certificate is attached.</p>
     */
    inline LoadBalancerTlsCertificate& WithLoadBalancerName(Aws::String&& value) { SetLoadBalancerName(std::move(value)); return *this;}

    /**
     * <p>The load balancer name where your SSL/TLS certificate is attached.</p>
     */
    inline LoadBalancerTlsCertificate& WithLoadBalancerName(const char* value) { SetLoadBalancerName(value); return *this;}


    /**
     * <p>When <code>true</code>, the SSL/TLS certificate is attached to the Lightsail
     * load balancer.</p>
     */
    inline bool GetIsAttached() const{ return m_isAttached; }

    /**
     * <p>When <code>true</code>, the SSL/TLS certificate is attached to the Lightsail
     * load balancer.</p>
     */
    inline bool IsAttachedHasBeenSet() const { return m_isAttachedHasBeenSet; }

    /**
     * <p>When <code>true</code>, the SSL/TLS certificate is attached to the Lightsail
     * load balancer.</p>
     */
    inline void SetIsAttached(bool value) { m_isAttachedHasBeenSet = true; m_isAttached = value; }

    /**
     * <p>When <code>true</code>, the SSL/TLS certificate is attached to the Lightsail
     * load balancer.</p>
     */
    inline LoadBalancerTlsCertificate& WithIsAttached(bool value) { SetIsAttached(value); return *this;}


    /**
     * <p>The validation status of the SSL/TLS certificate. Valid values are below.</p>
     */
    inline const LoadBalancerTlsCertificateStatus& GetStatus() const{ return m_status; }

    /**
     * <p>The validation status of the SSL/TLS certificate. Valid values are below.</p>
     */
    inline bool StatusHasBeenSet() const { return m_statusHasBeenSet; }

    /**
     * <p>The validation status of the SSL/TLS certificate. Valid values are below.</p>
     */
    inline void SetStatus(const LoadBalancerTlsCertificateStatus& value) { m_statusHasBeenSet = true; m_status = value; }

    /**
     * <p>The validation status of the SSL/TLS certificate. Valid values are below.</p>
     */
    inline void SetStatus(LoadBalancerTlsCertificateStatus&& value) { m_statusHasBeenSet = true; m_status = std::move(value); }

    /**
     * <p>The validation status of the SSL/TLS certificate. Valid values are below.</p>
     */
    inline LoadBalancerTlsCertificate& WithStatus(const LoadBalancerTlsCertificateStatus& value) { SetStatus(value); return *this;}

    /**
     * <p>The validation status of the SSL/TLS certificate. Valid values are below.</p>
     */
    inline LoadBalancerTlsCertificate& WithStatus(LoadBalancerTlsCertificateStatus&& value) { SetStatus(std::move(value)); return *this;}


    /**
     * <p>The domain name for your SSL/TLS certificate.</p>
     */
    inline const Aws::String& GetDomainName() const{ return m_domainName; }

    /**
     * <p>The domain name for your SSL/TLS certificate.</p>
     */
    inline bool DomainNameHasBeenSet() const { return m_domainNameHasBeenSet; }

    /**
     * <p>The domain name for your SSL/TLS certificate.</p>
     */
    inline void SetDomainName(const Aws::String& value) { m_domainNameHasBeenSet = true; m_domainName = value; }

    /**
     * <p>The domain name for your SSL/TLS certificate.</p>
     */
    inline void SetDomainName(Aws::String&& value) { m_domainNameHasBeenSet = true; m_domainName = std::move(value); }

    /**
     * <p>The domain name for your SSL/TLS certificate.</p>
     */
    inline void SetDomainName(const char* value) { m_domainNameHasBeenSet = true; m_domainName.assign(value); }

    /**
     * <p>The domain name for your SSL/TLS certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithDomainName(const Aws::String& value) { SetDomainName(value); return *this;}

    /**
     * <p>The domain name for your SSL/TLS certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithDomainName(Aws::String&& value) { SetDomainName(std::move(value)); return *this;}

    /**
     * <p>The domain name for your SSL/TLS certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithDomainName(const char* value) { SetDomainName(value); return *this;}


    /**
     * <p>An array of LoadBalancerTlsCertificateDomainValidationRecord objects
     * describing the records.</p>
     */
    inline const Aws::Vector<LoadBalancerTlsCertificateDomainValidationRecord>& GetDomainValidationRecords() const{ return m_domainValidationRecords; }

    /**
     * <p>An array of LoadBalancerTlsCertificateDomainValidationRecord objects
     * describing the records.</p>
     */
    inline bool DomainValidationRecordsHasBeenSet() const { return m_domainValidationRecordsHasBeenSet; }

    /**
     * <p>An array of LoadBalancerTlsCertificateDomainValidationRecord objects
     * describing the records.</p>
     */
    inline void SetDomainValidationRecords(const Aws::Vector<LoadBalancerTlsCertificateDomainValidationRecord>& value) { m_domainValidationRecordsHasBeenSet = true; m_domainValidationRecords = value; }

    /**
     * <p>An array of LoadBalancerTlsCertificateDomainValidationRecord objects
     * describing the records.</p>
     */
    inline void SetDomainValidationRecords(Aws::Vector<LoadBalancerTlsCertificateDomainValidationRecord>&& value) { m_domainValidationRecordsHasBeenSet = true; m_domainValidationRecords = std::move(value); }

    /**
     * <p>An array of LoadBalancerTlsCertificateDomainValidationRecord objects
     * describing the records.</p>
     */
    inline LoadBalancerTlsCertificate& WithDomainValidationRecords(const Aws::Vector<LoadBalancerTlsCertificateDomainValidationRecord>& value) { SetDomainValidationRecords(value); return *this;}

    /**
     * <p>An array of LoadBalancerTlsCertificateDomainValidationRecord objects
     * describing the records.</p>
     */
    inline LoadBalancerTlsCertificate& WithDomainValidationRecords(Aws::Vector<LoadBalancerTlsCertificateDomainValidationRecord>&& value) { SetDomainValidationRecords(std::move(value)); return *this;}

    /**
     * <p>An array of LoadBalancerTlsCertificateDomainValidationRecord objects
     * describing the records.</p>
     */
    inline LoadBalancerTlsCertificate& AddDomainValidationRecords(const LoadBalancerTlsCertificateDomainValidationRecord& value) { m_domainValidationRecordsHasBeenSet = true; m_domainValidationRecords.push_back(value); return *this; }

    /**
     * <p>An array of LoadBalancerTlsCertificateDomainValidationRecord objects
     * describing the records.</p>
     */
    inline LoadBalancerTlsCertificate& AddDomainValidationRecords(LoadBalancerTlsCertificateDomainValidationRecord&& value) { m_domainValidationRecordsHasBeenSet = true; m_domainValidationRecords.push_back(std::move(value)); return *this; }


    /**
     * <p>The validation failure reason, if any, of the certificate.</p> <p>The
     * following failure reasons are possible:</p> <ul> <li> <p> <b>
     * <code>NO_AVAILABLE_CONTACTS</code> </b> - This failure applies to email
     * validation, which is not available for Lightsail certificates.</p> </li> <li>
     * <p> <b> <code>ADDITIONAL_VERIFICATION_REQUIRED</code> </b> - Lightsail requires
     * additional information to process this certificate request. This can happen as a
     * fraud-protection measure, such as when the domain ranks within the Alexa top
     * 1000 websites. To provide the required information, use the <a
     * href="https://console.aws.amazon.com/support/home">AWS Support Center</a> to
     * contact AWS Support.</p>  <p>You cannot request a certificate for
     * Amazon-owned domain names such as those ending in amazonaws.com, cloudfront.net,
     * or elasticbeanstalk.com.</p>  </li> <li> <p> <b>
     * <code>DOMAIN_NOT_ALLOWED</code> </b> - One or more of the domain names in the
     * certificate request was reported as an unsafe domain by <a
     * href="https://www.virustotal.com/gui/home/url">VirusTotal</a>. To correct the
     * problem, search for your domain name on the <a
     * href="https://www.virustotal.com/gui/home/url">VirusTotal</a> website. If your
     * domain is reported as suspicious, see <a
     * href="https://developers.google.com/web/fundamentals/security/hacked">Google
     * Help for Hacked Websites</a> to learn what you can do.</p> <p>If you believe
     * that the result is a false positive, notify the organization that is reporting
     * the domain. VirusTotal is an aggregate of several antivirus and URL scanners and
     * cannot remove your domain from a block list itself. After you correct the
     * problem and the VirusTotal registry has been updated, request a new
     * certificate.</p> <p>If you see this error and your domain is not included in the
     * VirusTotal list, visit the <a
     * href="https://console.aws.amazon.com/support/home">AWS Support Center</a> and
     * create a case.</p> </li> <li> <p> <b> <code>INVALID_PUBLIC_DOMAIN</code> </b> -
     * One or more of the domain names in the certificate request is not valid.
     * Typically, this is because a domain name in the request is not a valid top-level
     * domain. Try to request a certificate again, correcting any spelling errors or
     * typos that were in the failed request, and ensure that all domain names in the
     * request are for valid top-level domains. For example, you cannot request a
     * certificate for <code>example.invalidpublicdomain</code> because
     * <code>invalidpublicdomain</code> is not a valid top-level domain.</p> </li> <li>
     * <p> <b> <code>OTHER</code> </b> - Typically, this failure occurs when there is a
     * typographical error in one or more of the domain names in the certificate
     * request. Try to request a certificate again, correcting any spelling errors or
     * typos that were in the failed request. </p> </li> </ul>
     */
    inline const LoadBalancerTlsCertificateFailureReason& GetFailureReason() const{ return m_failureReason; }

    /**
     * <p>The validation failure reason, if any, of the certificate.</p> <p>The
     * following failure reasons are possible:</p> <ul> <li> <p> <b>
     * <code>NO_AVAILABLE_CONTACTS</code> </b> - This failure applies to email
     * validation, which is not available for Lightsail certificates.</p> </li> <li>
     * <p> <b> <code>ADDITIONAL_VERIFICATION_REQUIRED</code> </b> - Lightsail requires
     * additional information to process this certificate request. This can happen as a
     * fraud-protection measure, such as when the domain ranks within the Alexa top
     * 1000 websites. To provide the required information, use the <a
     * href="https://console.aws.amazon.com/support/home">AWS Support Center</a> to
     * contact AWS Support.</p>  <p>You cannot request a certificate for
     * Amazon-owned domain names such as those ending in amazonaws.com, cloudfront.net,
     * or elasticbeanstalk.com.</p>  </li> <li> <p> <b>
     * <code>DOMAIN_NOT_ALLOWED</code> </b> - One or more of the domain names in the
     * certificate request was reported as an unsafe domain by <a
     * href="https://www.virustotal.com/gui/home/url">VirusTotal</a>. To correct the
     * problem, search for your domain name on the <a
     * href="https://www.virustotal.com/gui/home/url">VirusTotal</a> website. If your
     * domain is reported as suspicious, see <a
     * href="https://developers.google.com/web/fundamentals/security/hacked">Google
     * Help for Hacked Websites</a> to learn what you can do.</p> <p>If you believe
     * that the result is a false positive, notify the organization that is reporting
     * the domain. VirusTotal is an aggregate of several antivirus and URL scanners and
     * cannot remove your domain from a block list itself. After you correct the
     * problem and the VirusTotal registry has been updated, request a new
     * certificate.</p> <p>If you see this error and your domain is not included in the
     * VirusTotal list, visit the <a
     * href="https://console.aws.amazon.com/support/home">AWS Support Center</a> and
     * create a case.</p> </li> <li> <p> <b> <code>INVALID_PUBLIC_DOMAIN</code> </b> -
     * One or more of the domain names in the certificate request is not valid.
     * Typically, this is because a domain name in the request is not a valid top-level
     * domain. Try to request a certificate again, correcting any spelling errors or
     * typos that were in the failed request, and ensure that all domain names in the
     * request are for valid top-level domains. For example, you cannot request a
     * certificate for <code>example.invalidpublicdomain</code> because
     * <code>invalidpublicdomain</code> is not a valid top-level domain.</p> </li> <li>
     * <p> <b> <code>OTHER</code> </b> - Typically, this failure occurs when there is a
     * typographical error in one or more of the domain names in the certificate
     * request. Try to request a certificate again, correcting any spelling errors or
     * typos that were in the failed request. </p> </li> </ul>
     */
    inline bool FailureReasonHasBeenSet() const { return m_failureReasonHasBeenSet; }

    /**
     * <p>The validation failure reason, if any, of the certificate.</p> <p>The
     * following failure reasons are possible:</p> <ul> <li> <p> <b>
     * <code>NO_AVAILABLE_CONTACTS</code> </b> - This failure applies to email
     * validation, which is not available for Lightsail certificates.</p> </li> <li>
     * <p> <b> <code>ADDITIONAL_VERIFICATION_REQUIRED</code> </b> - Lightsail requires
     * additional information to process this certificate request. This can happen as a
     * fraud-protection measure, such as when the domain ranks within the Alexa top
     * 1000 websites. To provide the required information, use the <a
     * href="https://console.aws.amazon.com/support/home">AWS Support Center</a> to
     * contact AWS Support.</p>  <p>You cannot request a certificate for
     * Amazon-owned domain names such as those ending in amazonaws.com, cloudfront.net,
     * or elasticbeanstalk.com.</p>  </li> <li> <p> <b>
     * <code>DOMAIN_NOT_ALLOWED</code> </b> - One or more of the domain names in the
     * certificate request was reported as an unsafe domain by <a
     * href="https://www.virustotal.com/gui/home/url">VirusTotal</a>. To correct the
     * problem, search for your domain name on the <a
     * href="https://www.virustotal.com/gui/home/url">VirusTotal</a> website. If your
     * domain is reported as suspicious, see <a
     * href="https://developers.google.com/web/fundamentals/security/hacked">Google
     * Help for Hacked Websites</a> to learn what you can do.</p> <p>If you believe
     * that the result is a false positive, notify the organization that is reporting
     * the domain. VirusTotal is an aggregate of several antivirus and URL scanners and
     * cannot remove your domain from a block list itself. After you correct the
     * problem and the VirusTotal registry has been updated, request a new
     * certificate.</p> <p>If you see this error and your domain is not included in the
     * VirusTotal list, visit the <a
     * href="https://console.aws.amazon.com/support/home">AWS Support Center</a> and
     * create a case.</p> </li> <li> <p> <b> <code>INVALID_PUBLIC_DOMAIN</code> </b> -
     * One or more of the domain names in the certificate request is not valid.
     * Typically, this is because a domain name in the request is not a valid top-level
     * domain. Try to request a certificate again, correcting any spelling errors or
     * typos that were in the failed request, and ensure that all domain names in the
     * request are for valid top-level domains. For example, you cannot request a
     * certificate for <code>example.invalidpublicdomain</code> because
     * <code>invalidpublicdomain</code> is not a valid top-level domain.</p> </li> <li>
     * <p> <b> <code>OTHER</code> </b> - Typically, this failure occurs when there is a
     * typographical error in one or more of the domain names in the certificate
     * request. Try to request a certificate again, correcting any spelling errors or
     * typos that were in the failed request. </p> </li> </ul>
     */
    inline void SetFailureReason(const LoadBalancerTlsCertificateFailureReason& value) { m_failureReasonHasBeenSet = true; m_failureReason = value; }

    /**
     * <p>The validation failure reason, if any, of the certificate.</p> <p>The
     * following failure reasons are possible:</p> <ul> <li> <p> <b>
     * <code>NO_AVAILABLE_CONTACTS</code> </b> - This failure applies to email
     * validation, which is not available for Lightsail certificates.</p> </li> <li>
     * <p> <b> <code>ADDITIONAL_VERIFICATION_REQUIRED</code> </b> - Lightsail requires
     * additional information to process this certificate request. This can happen as a
     * fraud-protection measure, such as when the domain ranks within the Alexa top
     * 1000 websites. To provide the required information, use the <a
     * href="https://console.aws.amazon.com/support/home">AWS Support Center</a> to
     * contact AWS Support.</p>  <p>You cannot request a certificate for
     * Amazon-owned domain names such as those ending in amazonaws.com, cloudfront.net,
     * or elasticbeanstalk.com.</p>  </li> <li> <p> <b>
     * <code>DOMAIN_NOT_ALLOWED</code> </b> - One or more of the domain names in the
     * certificate request was reported as an unsafe domain by <a
     * href="https://www.virustotal.com/gui/home/url">VirusTotal</a>. To correct the
     * problem, search for your domain name on the <a
     * href="https://www.virustotal.com/gui/home/url">VirusTotal</a> website. If your
     * domain is reported as suspicious, see <a
     * href="https://developers.google.com/web/fundamentals/security/hacked">Google
     * Help for Hacked Websites</a> to learn what you can do.</p> <p>If you believe
     * that the result is a false positive, notify the organization that is reporting
     * the domain. VirusTotal is an aggregate of several antivirus and URL scanners and
     * cannot remove your domain from a block list itself. After you correct the
     * problem and the VirusTotal registry has been updated, request a new
     * certificate.</p> <p>If you see this error and your domain is not included in the
     * VirusTotal list, visit the <a
     * href="https://console.aws.amazon.com/support/home">AWS Support Center</a> and
     * create a case.</p> </li> <li> <p> <b> <code>INVALID_PUBLIC_DOMAIN</code> </b> -
     * One or more of the domain names in the certificate request is not valid.
     * Typically, this is because a domain name in the request is not a valid top-level
     * domain. Try to request a certificate again, correcting any spelling errors or
     * typos that were in the failed request, and ensure that all domain names in the
     * request are for valid top-level domains. For example, you cannot request a
     * certificate for <code>example.invalidpublicdomain</code> because
     * <code>invalidpublicdomain</code> is not a valid top-level domain.</p> </li> <li>
     * <p> <b> <code>OTHER</code> </b> - Typically, this failure occurs when there is a
     * typographical error in one or more of the domain names in the certificate
     * request. Try to request a certificate again, correcting any spelling errors or
     * typos that were in the failed request. </p> </li> </ul>
     */
    inline void SetFailureReason(LoadBalancerTlsCertificateFailureReason&& value) { m_failureReasonHasBeenSet = true; m_failureReason = std::move(value); }

    /**
     * <p>The validation failure reason, if any, of the certificate.</p> <p>The
     * following failure reasons are possible:</p> <ul> <li> <p> <b>
     * <code>NO_AVAILABLE_CONTACTS</code> </b> - This failure applies to email
     * validation, which is not available for Lightsail certificates.</p> </li> <li>
     * <p> <b> <code>ADDITIONAL_VERIFICATION_REQUIRED</code> </b> - Lightsail requires
     * additional information to process this certificate request. This can happen as a
     * fraud-protection measure, such as when the domain ranks within the Alexa top
     * 1000 websites. To provide the required information, use the <a
     * href="https://console.aws.amazon.com/support/home">AWS Support Center</a> to
     * contact AWS Support.</p>  <p>You cannot request a certificate for
     * Amazon-owned domain names such as those ending in amazonaws.com, cloudfront.net,
     * or elasticbeanstalk.com.</p>  </li> <li> <p> <b>
     * <code>DOMAIN_NOT_ALLOWED</code> </b> - One or more of the domain names in the
     * certificate request was reported as an unsafe domain by <a
     * href="https://www.virustotal.com/gui/home/url">VirusTotal</a>. To correct the
     * problem, search for your domain name on the <a
     * href="https://www.virustotal.com/gui/home/url">VirusTotal</a> website. If your
     * domain is reported as suspicious, see <a
     * href="https://developers.google.com/web/fundamentals/security/hacked">Google
     * Help for Hacked Websites</a> to learn what you can do.</p> <p>If you believe
     * that the result is a false positive, notify the organization that is reporting
     * the domain. VirusTotal is an aggregate of several antivirus and URL scanners and
     * cannot remove your domain from a block list itself. After you correct the
     * problem and the VirusTotal registry has been updated, request a new
     * certificate.</p> <p>If you see this error and your domain is not included in the
     * VirusTotal list, visit the <a
     * href="https://console.aws.amazon.com/support/home">AWS Support Center</a> and
     * create a case.</p> </li> <li> <p> <b> <code>INVALID_PUBLIC_DOMAIN</code> </b> -
     * One or more of the domain names in the certificate request is not valid.
     * Typically, this is because a domain name in the request is not a valid top-level
     * domain. Try to request a certificate again, correcting any spelling errors or
     * typos that were in the failed request, and ensure that all domain names in the
     * request are for valid top-level domains. For example, you cannot request a
     * certificate for <code>example.invalidpublicdomain</code> because
     * <code>invalidpublicdomain</code> is not a valid top-level domain.</p> </li> <li>
     * <p> <b> <code>OTHER</code> </b> - Typically, this failure occurs when there is a
     * typographical error in one or more of the domain names in the certificate
     * request. Try to request a certificate again, correcting any spelling errors or
     * typos that were in the failed request. </p> </li> </ul>
     */
    inline LoadBalancerTlsCertificate& WithFailureReason(const LoadBalancerTlsCertificateFailureReason& value) { SetFailureReason(value); return *this;}

    /**
     * <p>The validation failure reason, if any, of the certificate.</p> <p>The
     * following failure reasons are possible:</p> <ul> <li> <p> <b>
     * <code>NO_AVAILABLE_CONTACTS</code> </b> - This failure applies to email
     * validation, which is not available for Lightsail certificates.</p> </li> <li>
     * <p> <b> <code>ADDITIONAL_VERIFICATION_REQUIRED</code> </b> - Lightsail requires
     * additional information to process this certificate request. This can happen as a
     * fraud-protection measure, such as when the domain ranks within the Alexa top
     * 1000 websites. To provide the required information, use the <a
     * href="https://console.aws.amazon.com/support/home">AWS Support Center</a> to
     * contact AWS Support.</p>  <p>You cannot request a certificate for
     * Amazon-owned domain names such as those ending in amazonaws.com, cloudfront.net,
     * or elasticbeanstalk.com.</p>  </li> <li> <p> <b>
     * <code>DOMAIN_NOT_ALLOWED</code> </b> - One or more of the domain names in the
     * certificate request was reported as an unsafe domain by <a
     * href="https://www.virustotal.com/gui/home/url">VirusTotal</a>. To correct the
     * problem, search for your domain name on the <a
     * href="https://www.virustotal.com/gui/home/url">VirusTotal</a> website. If your
     * domain is reported as suspicious, see <a
     * href="https://developers.google.com/web/fundamentals/security/hacked">Google
     * Help for Hacked Websites</a> to learn what you can do.</p> <p>If you believe
     * that the result is a false positive, notify the organization that is reporting
     * the domain. VirusTotal is an aggregate of several antivirus and URL scanners and
     * cannot remove your domain from a block list itself. After you correct the
     * problem and the VirusTotal registry has been updated, request a new
     * certificate.</p> <p>If you see this error and your domain is not included in the
     * VirusTotal list, visit the <a
     * href="https://console.aws.amazon.com/support/home">AWS Support Center</a> and
     * create a case.</p> </li> <li> <p> <b> <code>INVALID_PUBLIC_DOMAIN</code> </b> -
     * One or more of the domain names in the certificate request is not valid.
     * Typically, this is because a domain name in the request is not a valid top-level
     * domain. Try to request a certificate again, correcting any spelling errors or
     * typos that were in the failed request, and ensure that all domain names in the
     * request are for valid top-level domains. For example, you cannot request a
     * certificate for <code>example.invalidpublicdomain</code> because
     * <code>invalidpublicdomain</code> is not a valid top-level domain.</p> </li> <li>
     * <p> <b> <code>OTHER</code> </b> - Typically, this failure occurs when there is a
     * typographical error in one or more of the domain names in the certificate
     * request. Try to request a certificate again, correcting any spelling errors or
     * typos that were in the failed request. </p> </li> </ul>
     */
    inline LoadBalancerTlsCertificate& WithFailureReason(LoadBalancerTlsCertificateFailureReason&& value) { SetFailureReason(std::move(value)); return *this;}


    /**
     * <p>The time when the SSL/TLS certificate was issued.</p>
     */
    inline const Aws::Utils::DateTime& GetIssuedAt() const{ return m_issuedAt; }

    /**
     * <p>The time when the SSL/TLS certificate was issued.</p>
     */
    inline bool IssuedAtHasBeenSet() const { return m_issuedAtHasBeenSet; }

    /**
     * <p>The time when the SSL/TLS certificate was issued.</p>
     */
    inline void SetIssuedAt(const Aws::Utils::DateTime& value) { m_issuedAtHasBeenSet = true; m_issuedAt = value; }

    /**
     * <p>The time when the SSL/TLS certificate was issued.</p>
     */
    inline void SetIssuedAt(Aws::Utils::DateTime&& value) { m_issuedAtHasBeenSet = true; m_issuedAt = std::move(value); }

    /**
     * <p>The time when the SSL/TLS certificate was issued.</p>
     */
    inline LoadBalancerTlsCertificate& WithIssuedAt(const Aws::Utils::DateTime& value) { SetIssuedAt(value); return *this;}

    /**
     * <p>The time when the SSL/TLS certificate was issued.</p>
     */
    inline LoadBalancerTlsCertificate& WithIssuedAt(Aws::Utils::DateTime&& value) { SetIssuedAt(std::move(value)); return *this;}


    /**
     * <p>The issuer of the certificate.</p>
     */
    inline const Aws::String& GetIssuer() const{ return m_issuer; }

    /**
     * <p>The issuer of the certificate.</p>
     */
    inline bool IssuerHasBeenSet() const { return m_issuerHasBeenSet; }

    /**
     * <p>The issuer of the certificate.</p>
     */
    inline void SetIssuer(const Aws::String& value) { m_issuerHasBeenSet = true; m_issuer = value; }

    /**
     * <p>The issuer of the certificate.</p>
     */
    inline void SetIssuer(Aws::String&& value) { m_issuerHasBeenSet = true; m_issuer = std::move(value); }

    /**
     * <p>The issuer of the certificate.</p>
     */
    inline void SetIssuer(const char* value) { m_issuerHasBeenSet = true; m_issuer.assign(value); }

    /**
     * <p>The issuer of the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithIssuer(const Aws::String& value) { SetIssuer(value); return *this;}

    /**
     * <p>The issuer of the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithIssuer(Aws::String&& value) { SetIssuer(std::move(value)); return *this;}

    /**
     * <p>The issuer of the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithIssuer(const char* value) { SetIssuer(value); return *this;}


    /**
     * <p>The algorithm used to generate the key pair (the public and private key).</p>
     */
    inline const Aws::String& GetKeyAlgorithm() const{ return m_keyAlgorithm; }

    /**
     * <p>The algorithm used to generate the key pair (the public and private key).</p>
     */
    inline bool KeyAlgorithmHasBeenSet() const { return m_keyAlgorithmHasBeenSet; }

    /**
     * <p>The algorithm used to generate the key pair (the public and private key).</p>
     */
    inline void SetKeyAlgorithm(const Aws::String& value) { m_keyAlgorithmHasBeenSet = true; m_keyAlgorithm = value; }

    /**
     * <p>The algorithm used to generate the key pair (the public and private key).</p>
     */
    inline void SetKeyAlgorithm(Aws::String&& value) { m_keyAlgorithmHasBeenSet = true; m_keyAlgorithm = std::move(value); }

    /**
     * <p>The algorithm used to generate the key pair (the public and private key).</p>
     */
    inline void SetKeyAlgorithm(const char* value) { m_keyAlgorithmHasBeenSet = true; m_keyAlgorithm.assign(value); }

    /**
     * <p>The algorithm used to generate the key pair (the public and private key).</p>
     */
    inline LoadBalancerTlsCertificate& WithKeyAlgorithm(const Aws::String& value) { SetKeyAlgorithm(value); return *this;}

    /**
     * <p>The algorithm used to generate the key pair (the public and private key).</p>
     */
    inline LoadBalancerTlsCertificate& WithKeyAlgorithm(Aws::String&& value) { SetKeyAlgorithm(std::move(value)); return *this;}

    /**
     * <p>The algorithm used to generate the key pair (the public and private key).</p>
     */
    inline LoadBalancerTlsCertificate& WithKeyAlgorithm(const char* value) { SetKeyAlgorithm(value); return *this;}


    /**
     * <p>The timestamp when the SSL/TLS certificate expires.</p>
     */
    inline const Aws::Utils::DateTime& GetNotAfter() const{ return m_notAfter; }

    /**
     * <p>The timestamp when the SSL/TLS certificate expires.</p>
     */
    inline bool NotAfterHasBeenSet() const { return m_notAfterHasBeenSet; }

    /**
     * <p>The timestamp when the SSL/TLS certificate expires.</p>
     */
    inline void SetNotAfter(const Aws::Utils::DateTime& value) { m_notAfterHasBeenSet = true; m_notAfter = value; }

    /**
     * <p>The timestamp when the SSL/TLS certificate expires.</p>
     */
    inline void SetNotAfter(Aws::Utils::DateTime&& value) { m_notAfterHasBeenSet = true; m_notAfter = std::move(value); }

    /**
     * <p>The timestamp when the SSL/TLS certificate expires.</p>
     */
    inline LoadBalancerTlsCertificate& WithNotAfter(const Aws::Utils::DateTime& value) { SetNotAfter(value); return *this;}

    /**
     * <p>The timestamp when the SSL/TLS certificate expires.</p>
     */
    inline LoadBalancerTlsCertificate& WithNotAfter(Aws::Utils::DateTime&& value) { SetNotAfter(std::move(value)); return *this;}


    /**
     * <p>The timestamp when the SSL/TLS certificate is first valid.</p>
     */
    inline const Aws::Utils::DateTime& GetNotBefore() const{ return m_notBefore; }

    /**
     * <p>The timestamp when the SSL/TLS certificate is first valid.</p>
     */
    inline bool NotBeforeHasBeenSet() const { return m_notBeforeHasBeenSet; }

    /**
     * <p>The timestamp when the SSL/TLS certificate is first valid.</p>
     */
    inline void SetNotBefore(const Aws::Utils::DateTime& value) { m_notBeforeHasBeenSet = true; m_notBefore = value; }

    /**
     * <p>The timestamp when the SSL/TLS certificate is first valid.</p>
     */
    inline void SetNotBefore(Aws::Utils::DateTime&& value) { m_notBeforeHasBeenSet = true; m_notBefore = std::move(value); }

    /**
     * <p>The timestamp when the SSL/TLS certificate is first valid.</p>
     */
    inline LoadBalancerTlsCertificate& WithNotBefore(const Aws::Utils::DateTime& value) { SetNotBefore(value); return *this;}

    /**
     * <p>The timestamp when the SSL/TLS certificate is first valid.</p>
     */
    inline LoadBalancerTlsCertificate& WithNotBefore(Aws::Utils::DateTime&& value) { SetNotBefore(std::move(value)); return *this;}


    /**
     * <p>An object that describes the status of the certificate renewal managed by
     * Lightsail.</p>
     */
    inline const LoadBalancerTlsCertificateRenewalSummary& GetRenewalSummary() const{ return m_renewalSummary; }

    /**
     * <p>An object that describes the status of the certificate renewal managed by
     * Lightsail.</p>
     */
    inline bool RenewalSummaryHasBeenSet() const { return m_renewalSummaryHasBeenSet; }

    /**
     * <p>An object that describes the status of the certificate renewal managed by
     * Lightsail.</p>
     */
    inline void SetRenewalSummary(const LoadBalancerTlsCertificateRenewalSummary& value) { m_renewalSummaryHasBeenSet = true; m_renewalSummary = value; }

    /**
     * <p>An object that describes the status of the certificate renewal managed by
     * Lightsail.</p>
     */
    inline void SetRenewalSummary(LoadBalancerTlsCertificateRenewalSummary&& value) { m_renewalSummaryHasBeenSet = true; m_renewalSummary = std::move(value); }

    /**
     * <p>An object that describes the status of the certificate renewal managed by
     * Lightsail.</p>
     */
    inline LoadBalancerTlsCertificate& WithRenewalSummary(const LoadBalancerTlsCertificateRenewalSummary& value) { SetRenewalSummary(value); return *this;}

    /**
     * <p>An object that describes the status of the certificate renewal managed by
     * Lightsail.</p>
     */
    inline LoadBalancerTlsCertificate& WithRenewalSummary(LoadBalancerTlsCertificateRenewalSummary&& value) { SetRenewalSummary(std::move(value)); return *this;}


    /**
     * <p>The reason the certificate was revoked. This value is present only when the
     * certificate status is <code>REVOKED</code>.</p>
     */
    inline const LoadBalancerTlsCertificateRevocationReason& GetRevocationReason() const{ return m_revocationReason; }

    /**
     * <p>The reason the certificate was revoked. This value is present only when the
     * certificate status is <code>REVOKED</code>.</p>
     */
    inline bool RevocationReasonHasBeenSet() const { return m_revocationReasonHasBeenSet; }

    /**
     * <p>The reason the certificate was revoked. This value is present only when the
     * certificate status is <code>REVOKED</code>.</p>
     */
    inline void SetRevocationReason(const LoadBalancerTlsCertificateRevocationReason& value) { m_revocationReasonHasBeenSet = true; m_revocationReason = value; }

    /**
     * <p>The reason the certificate was revoked. This value is present only when the
     * certificate status is <code>REVOKED</code>.</p>
     */
    inline void SetRevocationReason(LoadBalancerTlsCertificateRevocationReason&& value) { m_revocationReasonHasBeenSet = true; m_revocationReason = std::move(value); }

    /**
     * <p>The reason the certificate was revoked. This value is present only when the
     * certificate status is <code>REVOKED</code>.</p>
     */
    inline LoadBalancerTlsCertificate& WithRevocationReason(const LoadBalancerTlsCertificateRevocationReason& value) { SetRevocationReason(value); return *this;}

    /**
     * <p>The reason the certificate was revoked. This value is present only when the
     * certificate status is <code>REVOKED</code>.</p>
     */
    inline LoadBalancerTlsCertificate& WithRevocationReason(LoadBalancerTlsCertificateRevocationReason&& value) { SetRevocationReason(std::move(value)); return *this;}


    /**
     * <p>The timestamp when the certificate was revoked. This value is present only
     * when the certificate status is <code>REVOKED</code>.</p>
     */
    inline const Aws::Utils::DateTime& GetRevokedAt() const{ return m_revokedAt; }

    /**
     * <p>The timestamp when the certificate was revoked. This value is present only
     * when the certificate status is <code>REVOKED</code>.</p>
     */
    inline bool RevokedAtHasBeenSet() const { return m_revokedAtHasBeenSet; }

    /**
     * <p>The timestamp when the certificate was revoked. This value is present only
     * when the certificate status is <code>REVOKED</code>.</p>
     */
    inline void SetRevokedAt(const Aws::Utils::DateTime& value) { m_revokedAtHasBeenSet = true; m_revokedAt = value; }

    /**
     * <p>The timestamp when the certificate was revoked. This value is present only
     * when the certificate status is <code>REVOKED</code>.</p>
     */
    inline void SetRevokedAt(Aws::Utils::DateTime&& value) { m_revokedAtHasBeenSet = true; m_revokedAt = std::move(value); }

    /**
     * <p>The timestamp when the certificate was revoked. This value is present only
     * when the certificate status is <code>REVOKED</code>.</p>
     */
    inline LoadBalancerTlsCertificate& WithRevokedAt(const Aws::Utils::DateTime& value) { SetRevokedAt(value); return *this;}

    /**
     * <p>The timestamp when the certificate was revoked. This value is present only
     * when the certificate status is <code>REVOKED</code>.</p>
     */
    inline LoadBalancerTlsCertificate& WithRevokedAt(Aws::Utils::DateTime&& value) { SetRevokedAt(std::move(value)); return *this;}


    /**
     * <p>The serial number of the certificate.</p>
     */
    inline const Aws::String& GetSerial() const{ return m_serial; }

    /**
     * <p>The serial number of the certificate.</p>
     */
    inline bool SerialHasBeenSet() const { return m_serialHasBeenSet; }

    /**
     * <p>The serial number of the certificate.</p>
     */
    inline void SetSerial(const Aws::String& value) { m_serialHasBeenSet = true; m_serial = value; }

    /**
     * <p>The serial number of the certificate.</p>
     */
    inline void SetSerial(Aws::String&& value) { m_serialHasBeenSet = true; m_serial = std::move(value); }

    /**
     * <p>The serial number of the certificate.</p>
     */
    inline void SetSerial(const char* value) { m_serialHasBeenSet = true; m_serial.assign(value); }

    /**
     * <p>The serial number of the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithSerial(const Aws::String& value) { SetSerial(value); return *this;}

    /**
     * <p>The serial number of the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithSerial(Aws::String&& value) { SetSerial(std::move(value)); return *this;}

    /**
     * <p>The serial number of the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithSerial(const char* value) { SetSerial(value); return *this;}


    /**
     * <p>The algorithm that was used to sign the certificate.</p>
     */
    inline const Aws::String& GetSignatureAlgorithm() const{ return m_signatureAlgorithm; }

    /**
     * <p>The algorithm that was used to sign the certificate.</p>
     */
    inline bool SignatureAlgorithmHasBeenSet() const { return m_signatureAlgorithmHasBeenSet; }

    /**
     * <p>The algorithm that was used to sign the certificate.</p>
     */
    inline void SetSignatureAlgorithm(const Aws::String& value) { m_signatureAlgorithmHasBeenSet = true; m_signatureAlgorithm = value; }

    /**
     * <p>The algorithm that was used to sign the certificate.</p>
     */
    inline void SetSignatureAlgorithm(Aws::String&& value) { m_signatureAlgorithmHasBeenSet = true; m_signatureAlgorithm = std::move(value); }

    /**
     * <p>The algorithm that was used to sign the certificate.</p>
     */
    inline void SetSignatureAlgorithm(const char* value) { m_signatureAlgorithmHasBeenSet = true; m_signatureAlgorithm.assign(value); }

    /**
     * <p>The algorithm that was used to sign the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithSignatureAlgorithm(const Aws::String& value) { SetSignatureAlgorithm(value); return *this;}

    /**
     * <p>The algorithm that was used to sign the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithSignatureAlgorithm(Aws::String&& value) { SetSignatureAlgorithm(std::move(value)); return *this;}

    /**
     * <p>The algorithm that was used to sign the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithSignatureAlgorithm(const char* value) { SetSignatureAlgorithm(value); return *this;}


    /**
     * <p>The name of the entity that is associated with the public key contained in
     * the certificate.</p>
     */
    inline const Aws::String& GetSubject() const{ return m_subject; }

    /**
     * <p>The name of the entity that is associated with the public key contained in
     * the certificate.</p>
     */
    inline bool SubjectHasBeenSet() const { return m_subjectHasBeenSet; }

    /**
     * <p>The name of the entity that is associated with the public key contained in
     * the certificate.</p>
     */
    inline void SetSubject(const Aws::String& value) { m_subjectHasBeenSet = true; m_subject = value; }

    /**
     * <p>The name of the entity that is associated with the public key contained in
     * the certificate.</p>
     */
    inline void SetSubject(Aws::String&& value) { m_subjectHasBeenSet = true; m_subject = std::move(value); }

    /**
     * <p>The name of the entity that is associated with the public key contained in
     * the certificate.</p>
     */
    inline void SetSubject(const char* value) { m_subjectHasBeenSet = true; m_subject.assign(value); }

    /**
     * <p>The name of the entity that is associated with the public key contained in
     * the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithSubject(const Aws::String& value) { SetSubject(value); return *this;}

    /**
     * <p>The name of the entity that is associated with the public key contained in
     * the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithSubject(Aws::String&& value) { SetSubject(std::move(value)); return *this;}

    /**
     * <p>The name of the entity that is associated with the public key contained in
     * the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithSubject(const char* value) { SetSubject(value); return *this;}


    /**
     * <p>An array of strings that specify the alternate domains (e.g.,
     * <code>example2.com</code>) and subdomains (e.g., <code>blog.example.com</code>)
     * for the certificate.</p>
     */
    inline const Aws::Vector<Aws::String>& GetSubjectAlternativeNames() const{ return m_subjectAlternativeNames; }

    /**
     * <p>An array of strings that specify the alternate domains (e.g.,
     * <code>example2.com</code>) and subdomains (e.g., <code>blog.example.com</code>)
     * for the certificate.</p>
     */
    inline bool SubjectAlternativeNamesHasBeenSet() const { return m_subjectAlternativeNamesHasBeenSet; }

    /**
     * <p>An array of strings that specify the alternate domains (e.g.,
     * <code>example2.com</code>) and subdomains (e.g., <code>blog.example.com</code>)
     * for the certificate.</p>
     */
    inline void SetSubjectAlternativeNames(const Aws::Vector<Aws::String>& value) { m_subjectAlternativeNamesHasBeenSet = true; m_subjectAlternativeNames = value; }

    /**
     * <p>An array of strings that specify the alternate domains (e.g.,
     * <code>example2.com</code>) and subdomains (e.g., <code>blog.example.com</code>)
     * for the certificate.</p>
     */
    inline void SetSubjectAlternativeNames(Aws::Vector<Aws::String>&& value) { m_subjectAlternativeNamesHasBeenSet = true; m_subjectAlternativeNames = std::move(value); }

    /**
     * <p>An array of strings that specify the alternate domains (e.g.,
     * <code>example2.com</code>) and subdomains (e.g., <code>blog.example.com</code>)
     * for the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithSubjectAlternativeNames(const Aws::Vector<Aws::String>& value) { SetSubjectAlternativeNames(value); return *this;}

    /**
     * <p>An array of strings that specify the alternate domains (e.g.,
     * <code>example2.com</code>) and subdomains (e.g., <code>blog.example.com</code>)
     * for the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& WithSubjectAlternativeNames(Aws::Vector<Aws::String>&& value) { SetSubjectAlternativeNames(std::move(value)); return *this;}

    /**
     * <p>An array of strings that specify the alternate domains (e.g.,
     * <code>example2.com</code>) and subdomains (e.g., <code>blog.example.com</code>)
     * for the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& AddSubjectAlternativeNames(const Aws::String& value) { m_subjectAlternativeNamesHasBeenSet = true; m_subjectAlternativeNames.push_back(value); return *this; }

    /**
     * <p>An array of strings that specify the alternate domains (e.g.,
     * <code>example2.com</code>) and subdomains (e.g., <code>blog.example.com</code>)
     * for the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& AddSubjectAlternativeNames(Aws::String&& value) { m_subjectAlternativeNamesHasBeenSet = true; m_subjectAlternativeNames.push_back(std::move(value)); return *this; }

    /**
     * <p>An array of strings that specify the alternate domains (e.g.,
     * <code>example2.com</code>) and subdomains (e.g., <code>blog.example.com</code>)
     * for the certificate.</p>
     */
    inline LoadBalancerTlsCertificate& AddSubjectAlternativeNames(const char* value) { m_subjectAlternativeNamesHasBeenSet = true; m_subjectAlternativeNames.push_back(value); return *this; }

  private:

    Aws::String m_name;
    bool m_nameHasBeenSet = false;

    Aws::String m_arn;
    bool m_arnHasBeenSet = false;

    Aws::String m_supportCode;
    bool m_supportCodeHasBeenSet = false;

    Aws::Utils::DateTime m_createdAt;
    bool m_createdAtHasBeenSet = false;

    ResourceLocation m_location;
    bool m_locationHasBeenSet = false;

    ResourceType m_resourceType;
    bool m_resourceTypeHasBeenSet = false;

    Aws::Vector<Tag> m_tags;
    bool m_tagsHasBeenSet = false;

    Aws::String m_loadBalancerName;
    bool m_loadBalancerNameHasBeenSet = false;

    bool m_isAttached;
    bool m_isAttachedHasBeenSet = false;

    LoadBalancerTlsCertificateStatus m_status;
    bool m_statusHasBeenSet = false;

    Aws::String m_domainName;
    bool m_domainNameHasBeenSet = false;

    Aws::Vector<LoadBalancerTlsCertificateDomainValidationRecord> m_domainValidationRecords;
    bool m_domainValidationRecordsHasBeenSet = false;

    LoadBalancerTlsCertificateFailureReason m_failureReason;
    bool m_failureReasonHasBeenSet = false;

    Aws::Utils::DateTime m_issuedAt;
    bool m_issuedAtHasBeenSet = false;

    Aws::String m_issuer;
    bool m_issuerHasBeenSet = false;

    Aws::String m_keyAlgorithm;
    bool m_keyAlgorithmHasBeenSet = false;

    Aws::Utils::DateTime m_notAfter;
    bool m_notAfterHasBeenSet = false;

    Aws::Utils::DateTime m_notBefore;
    bool m_notBeforeHasBeenSet = false;

    LoadBalancerTlsCertificateRenewalSummary m_renewalSummary;
    bool m_renewalSummaryHasBeenSet = false;

    LoadBalancerTlsCertificateRevocationReason m_revocationReason;
    bool m_revocationReasonHasBeenSet = false;

    Aws::Utils::DateTime m_revokedAt;
    bool m_revokedAtHasBeenSet = false;

    Aws::String m_serial;
    bool m_serialHasBeenSet = false;

    Aws::String m_signatureAlgorithm;
    bool m_signatureAlgorithmHasBeenSet = false;

    Aws::String m_subject;
    bool m_subjectHasBeenSet = false;

    Aws::Vector<Aws::String> m_subjectAlternativeNames;
    bool m_subjectAlternativeNamesHasBeenSet = false;
  };

} // namespace Model
} // namespace Lightsail
} // namespace Aws
