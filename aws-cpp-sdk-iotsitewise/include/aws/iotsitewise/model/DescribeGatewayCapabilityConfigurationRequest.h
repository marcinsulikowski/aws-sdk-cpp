﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/iotsitewise/IoTSiteWise_EXPORTS.h>
#include <aws/iotsitewise/IoTSiteWiseRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace IoTSiteWise
{
namespace Model
{

  /**
   */
  class AWS_IOTSITEWISE_API DescribeGatewayCapabilityConfigurationRequest : public IoTSiteWiseRequest
  {
  public:
    DescribeGatewayCapabilityConfigurationRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DescribeGatewayCapabilityConfiguration"; }

    Aws::String SerializePayload() const override;


    /**
     * <p>The ID of the gateway that defines the capability configuration.</p>
     */
    inline const Aws::String& GetGatewayId() const{ return m_gatewayId; }

    /**
     * <p>The ID of the gateway that defines the capability configuration.</p>
     */
    inline bool GatewayIdHasBeenSet() const { return m_gatewayIdHasBeenSet; }

    /**
     * <p>The ID of the gateway that defines the capability configuration.</p>
     */
    inline void SetGatewayId(const Aws::String& value) { m_gatewayIdHasBeenSet = true; m_gatewayId = value; }

    /**
     * <p>The ID of the gateway that defines the capability configuration.</p>
     */
    inline void SetGatewayId(Aws::String&& value) { m_gatewayIdHasBeenSet = true; m_gatewayId = std::move(value); }

    /**
     * <p>The ID of the gateway that defines the capability configuration.</p>
     */
    inline void SetGatewayId(const char* value) { m_gatewayIdHasBeenSet = true; m_gatewayId.assign(value); }

    /**
     * <p>The ID of the gateway that defines the capability configuration.</p>
     */
    inline DescribeGatewayCapabilityConfigurationRequest& WithGatewayId(const Aws::String& value) { SetGatewayId(value); return *this;}

    /**
     * <p>The ID of the gateway that defines the capability configuration.</p>
     */
    inline DescribeGatewayCapabilityConfigurationRequest& WithGatewayId(Aws::String&& value) { SetGatewayId(std::move(value)); return *this;}

    /**
     * <p>The ID of the gateway that defines the capability configuration.</p>
     */
    inline DescribeGatewayCapabilityConfigurationRequest& WithGatewayId(const char* value) { SetGatewayId(value); return *this;}


    /**
     * <p>The namespace of the capability configuration. For example, if you configure
     * OPC-UA sources from the IoT SiteWise console, your OPC-UA capability
     * configuration has the namespace <code>iotsitewise:opcuacollector:version</code>,
     * where <code>version</code> is a number such as <code>1</code>.</p>
     */
    inline const Aws::String& GetCapabilityNamespace() const{ return m_capabilityNamespace; }

    /**
     * <p>The namespace of the capability configuration. For example, if you configure
     * OPC-UA sources from the IoT SiteWise console, your OPC-UA capability
     * configuration has the namespace <code>iotsitewise:opcuacollector:version</code>,
     * where <code>version</code> is a number such as <code>1</code>.</p>
     */
    inline bool CapabilityNamespaceHasBeenSet() const { return m_capabilityNamespaceHasBeenSet; }

    /**
     * <p>The namespace of the capability configuration. For example, if you configure
     * OPC-UA sources from the IoT SiteWise console, your OPC-UA capability
     * configuration has the namespace <code>iotsitewise:opcuacollector:version</code>,
     * where <code>version</code> is a number such as <code>1</code>.</p>
     */
    inline void SetCapabilityNamespace(const Aws::String& value) { m_capabilityNamespaceHasBeenSet = true; m_capabilityNamespace = value; }

    /**
     * <p>The namespace of the capability configuration. For example, if you configure
     * OPC-UA sources from the IoT SiteWise console, your OPC-UA capability
     * configuration has the namespace <code>iotsitewise:opcuacollector:version</code>,
     * where <code>version</code> is a number such as <code>1</code>.</p>
     */
    inline void SetCapabilityNamespace(Aws::String&& value) { m_capabilityNamespaceHasBeenSet = true; m_capabilityNamespace = std::move(value); }

    /**
     * <p>The namespace of the capability configuration. For example, if you configure
     * OPC-UA sources from the IoT SiteWise console, your OPC-UA capability
     * configuration has the namespace <code>iotsitewise:opcuacollector:version</code>,
     * where <code>version</code> is a number such as <code>1</code>.</p>
     */
    inline void SetCapabilityNamespace(const char* value) { m_capabilityNamespaceHasBeenSet = true; m_capabilityNamespace.assign(value); }

    /**
     * <p>The namespace of the capability configuration. For example, if you configure
     * OPC-UA sources from the IoT SiteWise console, your OPC-UA capability
     * configuration has the namespace <code>iotsitewise:opcuacollector:version</code>,
     * where <code>version</code> is a number such as <code>1</code>.</p>
     */
    inline DescribeGatewayCapabilityConfigurationRequest& WithCapabilityNamespace(const Aws::String& value) { SetCapabilityNamespace(value); return *this;}

    /**
     * <p>The namespace of the capability configuration. For example, if you configure
     * OPC-UA sources from the IoT SiteWise console, your OPC-UA capability
     * configuration has the namespace <code>iotsitewise:opcuacollector:version</code>,
     * where <code>version</code> is a number such as <code>1</code>.</p>
     */
    inline DescribeGatewayCapabilityConfigurationRequest& WithCapabilityNamespace(Aws::String&& value) { SetCapabilityNamespace(std::move(value)); return *this;}

    /**
     * <p>The namespace of the capability configuration. For example, if you configure
     * OPC-UA sources from the IoT SiteWise console, your OPC-UA capability
     * configuration has the namespace <code>iotsitewise:opcuacollector:version</code>,
     * where <code>version</code> is a number such as <code>1</code>.</p>
     */
    inline DescribeGatewayCapabilityConfigurationRequest& WithCapabilityNamespace(const char* value) { SetCapabilityNamespace(value); return *this;}

  private:

    Aws::String m_gatewayId;
    bool m_gatewayIdHasBeenSet = false;

    Aws::String m_capabilityNamespace;
    bool m_capabilityNamespaceHasBeenSet = false;
  };

} // namespace Model
} // namespace IoTSiteWise
} // namespace Aws
