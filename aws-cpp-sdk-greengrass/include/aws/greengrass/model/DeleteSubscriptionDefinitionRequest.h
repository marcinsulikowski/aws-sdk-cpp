﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/greengrass/Greengrass_EXPORTS.h>
#include <aws/greengrass/GreengrassRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Greengrass
{
namespace Model
{

  /**
   */
  class AWS_GREENGRASS_API DeleteSubscriptionDefinitionRequest : public GreengrassRequest
  {
  public:
    DeleteSubscriptionDefinitionRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DeleteSubscriptionDefinition"; }

    Aws::String SerializePayload() const override;


    /**
     * The ID of the subscription definition.
     */
    inline const Aws::String& GetSubscriptionDefinitionId() const{ return m_subscriptionDefinitionId; }

    /**
     * The ID of the subscription definition.
     */
    inline bool SubscriptionDefinitionIdHasBeenSet() const { return m_subscriptionDefinitionIdHasBeenSet; }

    /**
     * The ID of the subscription definition.
     */
    inline void SetSubscriptionDefinitionId(const Aws::String& value) { m_subscriptionDefinitionIdHasBeenSet = true; m_subscriptionDefinitionId = value; }

    /**
     * The ID of the subscription definition.
     */
    inline void SetSubscriptionDefinitionId(Aws::String&& value) { m_subscriptionDefinitionIdHasBeenSet = true; m_subscriptionDefinitionId = std::move(value); }

    /**
     * The ID of the subscription definition.
     */
    inline void SetSubscriptionDefinitionId(const char* value) { m_subscriptionDefinitionIdHasBeenSet = true; m_subscriptionDefinitionId.assign(value); }

    /**
     * The ID of the subscription definition.
     */
    inline DeleteSubscriptionDefinitionRequest& WithSubscriptionDefinitionId(const Aws::String& value) { SetSubscriptionDefinitionId(value); return *this;}

    /**
     * The ID of the subscription definition.
     */
    inline DeleteSubscriptionDefinitionRequest& WithSubscriptionDefinitionId(Aws::String&& value) { SetSubscriptionDefinitionId(std::move(value)); return *this;}

    /**
     * The ID of the subscription definition.
     */
    inline DeleteSubscriptionDefinitionRequest& WithSubscriptionDefinitionId(const char* value) { SetSubscriptionDefinitionId(value); return *this;}

  private:

    Aws::String m_subscriptionDefinitionId;
    bool m_subscriptionDefinitionIdHasBeenSet = false;
  };

} // namespace Model
} // namespace Greengrass
} // namespace Aws
