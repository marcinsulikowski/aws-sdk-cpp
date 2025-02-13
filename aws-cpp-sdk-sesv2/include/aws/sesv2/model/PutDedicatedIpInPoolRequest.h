﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/sesv2/SESV2_EXPORTS.h>
#include <aws/sesv2/SESV2Request.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace SESV2
{
namespace Model
{

  /**
   * <p>A request to move a dedicated IP address to a dedicated IP
   * pool.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/sesv2-2019-09-27/PutDedicatedIpInPoolRequest">AWS
   * API Reference</a></p>
   */
  class AWS_SESV2_API PutDedicatedIpInPoolRequest : public SESV2Request
  {
  public:
    PutDedicatedIpInPoolRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "PutDedicatedIpInPool"; }

    Aws::String SerializePayload() const override;


    /**
     * <p>The IP address that you want to move to the dedicated IP pool. The value you
     * specify has to be a dedicated IP address that's associated with your Amazon Web
     * Services account.</p>
     */
    inline const Aws::String& GetIp() const{ return m_ip; }

    /**
     * <p>The IP address that you want to move to the dedicated IP pool. The value you
     * specify has to be a dedicated IP address that's associated with your Amazon Web
     * Services account.</p>
     */
    inline bool IpHasBeenSet() const { return m_ipHasBeenSet; }

    /**
     * <p>The IP address that you want to move to the dedicated IP pool. The value you
     * specify has to be a dedicated IP address that's associated with your Amazon Web
     * Services account.</p>
     */
    inline void SetIp(const Aws::String& value) { m_ipHasBeenSet = true; m_ip = value; }

    /**
     * <p>The IP address that you want to move to the dedicated IP pool. The value you
     * specify has to be a dedicated IP address that's associated with your Amazon Web
     * Services account.</p>
     */
    inline void SetIp(Aws::String&& value) { m_ipHasBeenSet = true; m_ip = std::move(value); }

    /**
     * <p>The IP address that you want to move to the dedicated IP pool. The value you
     * specify has to be a dedicated IP address that's associated with your Amazon Web
     * Services account.</p>
     */
    inline void SetIp(const char* value) { m_ipHasBeenSet = true; m_ip.assign(value); }

    /**
     * <p>The IP address that you want to move to the dedicated IP pool. The value you
     * specify has to be a dedicated IP address that's associated with your Amazon Web
     * Services account.</p>
     */
    inline PutDedicatedIpInPoolRequest& WithIp(const Aws::String& value) { SetIp(value); return *this;}

    /**
     * <p>The IP address that you want to move to the dedicated IP pool. The value you
     * specify has to be a dedicated IP address that's associated with your Amazon Web
     * Services account.</p>
     */
    inline PutDedicatedIpInPoolRequest& WithIp(Aws::String&& value) { SetIp(std::move(value)); return *this;}

    /**
     * <p>The IP address that you want to move to the dedicated IP pool. The value you
     * specify has to be a dedicated IP address that's associated with your Amazon Web
     * Services account.</p>
     */
    inline PutDedicatedIpInPoolRequest& WithIp(const char* value) { SetIp(value); return *this;}


    /**
     * <p>The name of the IP pool that you want to add the dedicated IP address to. You
     * have to specify an IP pool that already exists.</p>
     */
    inline const Aws::String& GetDestinationPoolName() const{ return m_destinationPoolName; }

    /**
     * <p>The name of the IP pool that you want to add the dedicated IP address to. You
     * have to specify an IP pool that already exists.</p>
     */
    inline bool DestinationPoolNameHasBeenSet() const { return m_destinationPoolNameHasBeenSet; }

    /**
     * <p>The name of the IP pool that you want to add the dedicated IP address to. You
     * have to specify an IP pool that already exists.</p>
     */
    inline void SetDestinationPoolName(const Aws::String& value) { m_destinationPoolNameHasBeenSet = true; m_destinationPoolName = value; }

    /**
     * <p>The name of the IP pool that you want to add the dedicated IP address to. You
     * have to specify an IP pool that already exists.</p>
     */
    inline void SetDestinationPoolName(Aws::String&& value) { m_destinationPoolNameHasBeenSet = true; m_destinationPoolName = std::move(value); }

    /**
     * <p>The name of the IP pool that you want to add the dedicated IP address to. You
     * have to specify an IP pool that already exists.</p>
     */
    inline void SetDestinationPoolName(const char* value) { m_destinationPoolNameHasBeenSet = true; m_destinationPoolName.assign(value); }

    /**
     * <p>The name of the IP pool that you want to add the dedicated IP address to. You
     * have to specify an IP pool that already exists.</p>
     */
    inline PutDedicatedIpInPoolRequest& WithDestinationPoolName(const Aws::String& value) { SetDestinationPoolName(value); return *this;}

    /**
     * <p>The name of the IP pool that you want to add the dedicated IP address to. You
     * have to specify an IP pool that already exists.</p>
     */
    inline PutDedicatedIpInPoolRequest& WithDestinationPoolName(Aws::String&& value) { SetDestinationPoolName(std::move(value)); return *this;}

    /**
     * <p>The name of the IP pool that you want to add the dedicated IP address to. You
     * have to specify an IP pool that already exists.</p>
     */
    inline PutDedicatedIpInPoolRequest& WithDestinationPoolName(const char* value) { SetDestinationPoolName(value); return *this;}

  private:

    Aws::String m_ip;
    bool m_ipHasBeenSet = false;

    Aws::String m_destinationPoolName;
    bool m_destinationPoolNameHasBeenSet = false;
  };

} // namespace Model
} // namespace SESV2
} // namespace Aws
