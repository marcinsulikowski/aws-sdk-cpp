﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/rds/RDS_EXPORTS.h>
#include <aws/rds/RDSRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <utility>

namespace Aws
{
namespace RDS
{
namespace Model
{

  /**
   * <p/><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/rds-2014-10-31/ModifyEventSubscriptionMessage">AWS
   * API Reference</a></p>
   */
  class AWS_RDS_API ModifyEventSubscriptionRequest : public RDSRequest
  {
  public:
    ModifyEventSubscriptionRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "ModifyEventSubscription"; }

    Aws::String SerializePayload() const override;

  protected:
    void DumpBodyToUrl(Aws::Http::URI& uri ) const override;

  public:

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline const Aws::String& GetSubscriptionName() const{ return m_subscriptionName; }

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline bool SubscriptionNameHasBeenSet() const { return m_subscriptionNameHasBeenSet; }

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline void SetSubscriptionName(const Aws::String& value) { m_subscriptionNameHasBeenSet = true; m_subscriptionName = value; }

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline void SetSubscriptionName(Aws::String&& value) { m_subscriptionNameHasBeenSet = true; m_subscriptionName = std::move(value); }

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline void SetSubscriptionName(const char* value) { m_subscriptionNameHasBeenSet = true; m_subscriptionName.assign(value); }

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline ModifyEventSubscriptionRequest& WithSubscriptionName(const Aws::String& value) { SetSubscriptionName(value); return *this;}

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline ModifyEventSubscriptionRequest& WithSubscriptionName(Aws::String&& value) { SetSubscriptionName(std::move(value)); return *this;}

    /**
     * <p>The name of the RDS event notification subscription.</p>
     */
    inline ModifyEventSubscriptionRequest& WithSubscriptionName(const char* value) { SetSubscriptionName(value); return *this;}


    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it.</p>
     */
    inline const Aws::String& GetSnsTopicArn() const{ return m_snsTopicArn; }

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it.</p>
     */
    inline bool SnsTopicArnHasBeenSet() const { return m_snsTopicArnHasBeenSet; }

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it.</p>
     */
    inline void SetSnsTopicArn(const Aws::String& value) { m_snsTopicArnHasBeenSet = true; m_snsTopicArn = value; }

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it.</p>
     */
    inline void SetSnsTopicArn(Aws::String&& value) { m_snsTopicArnHasBeenSet = true; m_snsTopicArn = std::move(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it.</p>
     */
    inline void SetSnsTopicArn(const char* value) { m_snsTopicArnHasBeenSet = true; m_snsTopicArn.assign(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it.</p>
     */
    inline ModifyEventSubscriptionRequest& WithSnsTopicArn(const Aws::String& value) { SetSnsTopicArn(value); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it.</p>
     */
    inline ModifyEventSubscriptionRequest& WithSnsTopicArn(Aws::String&& value) { SetSnsTopicArn(std::move(value)); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the SNS topic created for event
     * notification. The ARN is created by Amazon SNS when you create a topic and
     * subscribe to it.</p>
     */
    inline ModifyEventSubscriptionRequest& WithSnsTopicArn(const char* value) { SetSnsTopicArn(value); return *this;}


    /**
     * <p>The type of source that is generating the events. For example, if you want to
     * be notified of events generated by a DB instance, you would set this parameter
     * to db-instance. For RDS Proxy events, specify <code>db-proxy</code>. If this
     * value isn't specified, all events are returned.</p> <p>Valid values:
     * <code>db-instance</code> | <code>db-cluster</code> |
     * <code>db-parameter-group</code> | <code>db-security-group</code> |
     * <code>db-snapshot</code> | <code>db-cluster-snapshot</code> |
     * <code>db-proxy</code> </p>
     */
    inline const Aws::String& GetSourceType() const{ return m_sourceType; }

    /**
     * <p>The type of source that is generating the events. For example, if you want to
     * be notified of events generated by a DB instance, you would set this parameter
     * to db-instance. For RDS Proxy events, specify <code>db-proxy</code>. If this
     * value isn't specified, all events are returned.</p> <p>Valid values:
     * <code>db-instance</code> | <code>db-cluster</code> |
     * <code>db-parameter-group</code> | <code>db-security-group</code> |
     * <code>db-snapshot</code> | <code>db-cluster-snapshot</code> |
     * <code>db-proxy</code> </p>
     */
    inline bool SourceTypeHasBeenSet() const { return m_sourceTypeHasBeenSet; }

    /**
     * <p>The type of source that is generating the events. For example, if you want to
     * be notified of events generated by a DB instance, you would set this parameter
     * to db-instance. For RDS Proxy events, specify <code>db-proxy</code>. If this
     * value isn't specified, all events are returned.</p> <p>Valid values:
     * <code>db-instance</code> | <code>db-cluster</code> |
     * <code>db-parameter-group</code> | <code>db-security-group</code> |
     * <code>db-snapshot</code> | <code>db-cluster-snapshot</code> |
     * <code>db-proxy</code> </p>
     */
    inline void SetSourceType(const Aws::String& value) { m_sourceTypeHasBeenSet = true; m_sourceType = value; }

    /**
     * <p>The type of source that is generating the events. For example, if you want to
     * be notified of events generated by a DB instance, you would set this parameter
     * to db-instance. For RDS Proxy events, specify <code>db-proxy</code>. If this
     * value isn't specified, all events are returned.</p> <p>Valid values:
     * <code>db-instance</code> | <code>db-cluster</code> |
     * <code>db-parameter-group</code> | <code>db-security-group</code> |
     * <code>db-snapshot</code> | <code>db-cluster-snapshot</code> |
     * <code>db-proxy</code> </p>
     */
    inline void SetSourceType(Aws::String&& value) { m_sourceTypeHasBeenSet = true; m_sourceType = std::move(value); }

    /**
     * <p>The type of source that is generating the events. For example, if you want to
     * be notified of events generated by a DB instance, you would set this parameter
     * to db-instance. For RDS Proxy events, specify <code>db-proxy</code>. If this
     * value isn't specified, all events are returned.</p> <p>Valid values:
     * <code>db-instance</code> | <code>db-cluster</code> |
     * <code>db-parameter-group</code> | <code>db-security-group</code> |
     * <code>db-snapshot</code> | <code>db-cluster-snapshot</code> |
     * <code>db-proxy</code> </p>
     */
    inline void SetSourceType(const char* value) { m_sourceTypeHasBeenSet = true; m_sourceType.assign(value); }

    /**
     * <p>The type of source that is generating the events. For example, if you want to
     * be notified of events generated by a DB instance, you would set this parameter
     * to db-instance. For RDS Proxy events, specify <code>db-proxy</code>. If this
     * value isn't specified, all events are returned.</p> <p>Valid values:
     * <code>db-instance</code> | <code>db-cluster</code> |
     * <code>db-parameter-group</code> | <code>db-security-group</code> |
     * <code>db-snapshot</code> | <code>db-cluster-snapshot</code> |
     * <code>db-proxy</code> </p>
     */
    inline ModifyEventSubscriptionRequest& WithSourceType(const Aws::String& value) { SetSourceType(value); return *this;}

    /**
     * <p>The type of source that is generating the events. For example, if you want to
     * be notified of events generated by a DB instance, you would set this parameter
     * to db-instance. For RDS Proxy events, specify <code>db-proxy</code>. If this
     * value isn't specified, all events are returned.</p> <p>Valid values:
     * <code>db-instance</code> | <code>db-cluster</code> |
     * <code>db-parameter-group</code> | <code>db-security-group</code> |
     * <code>db-snapshot</code> | <code>db-cluster-snapshot</code> |
     * <code>db-proxy</code> </p>
     */
    inline ModifyEventSubscriptionRequest& WithSourceType(Aws::String&& value) { SetSourceType(std::move(value)); return *this;}

    /**
     * <p>The type of source that is generating the events. For example, if you want to
     * be notified of events generated by a DB instance, you would set this parameter
     * to db-instance. For RDS Proxy events, specify <code>db-proxy</code>. If this
     * value isn't specified, all events are returned.</p> <p>Valid values:
     * <code>db-instance</code> | <code>db-cluster</code> |
     * <code>db-parameter-group</code> | <code>db-security-group</code> |
     * <code>db-snapshot</code> | <code>db-cluster-snapshot</code> |
     * <code>db-proxy</code> </p>
     */
    inline ModifyEventSubscriptionRequest& WithSourceType(const char* value) { SetSourceType(value); return *this;}


    /**
     * <p>A list of event categories for a source type (<code>SourceType</code>) that
     * you want to subscribe to. You can see a list of the categories for a given
     * source type in <a
     * href="https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * in the <i>Amazon RDS User Guide</i> or by using the
     * <code>DescribeEventCategories</code> operation.</p>
     */
    inline const Aws::Vector<Aws::String>& GetEventCategories() const{ return m_eventCategories; }

    /**
     * <p>A list of event categories for a source type (<code>SourceType</code>) that
     * you want to subscribe to. You can see a list of the categories for a given
     * source type in <a
     * href="https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * in the <i>Amazon RDS User Guide</i> or by using the
     * <code>DescribeEventCategories</code> operation.</p>
     */
    inline bool EventCategoriesHasBeenSet() const { return m_eventCategoriesHasBeenSet; }

    /**
     * <p>A list of event categories for a source type (<code>SourceType</code>) that
     * you want to subscribe to. You can see a list of the categories for a given
     * source type in <a
     * href="https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * in the <i>Amazon RDS User Guide</i> or by using the
     * <code>DescribeEventCategories</code> operation.</p>
     */
    inline void SetEventCategories(const Aws::Vector<Aws::String>& value) { m_eventCategoriesHasBeenSet = true; m_eventCategories = value; }

    /**
     * <p>A list of event categories for a source type (<code>SourceType</code>) that
     * you want to subscribe to. You can see a list of the categories for a given
     * source type in <a
     * href="https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * in the <i>Amazon RDS User Guide</i> or by using the
     * <code>DescribeEventCategories</code> operation.</p>
     */
    inline void SetEventCategories(Aws::Vector<Aws::String>&& value) { m_eventCategoriesHasBeenSet = true; m_eventCategories = std::move(value); }

    /**
     * <p>A list of event categories for a source type (<code>SourceType</code>) that
     * you want to subscribe to. You can see a list of the categories for a given
     * source type in <a
     * href="https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * in the <i>Amazon RDS User Guide</i> or by using the
     * <code>DescribeEventCategories</code> operation.</p>
     */
    inline ModifyEventSubscriptionRequest& WithEventCategories(const Aws::Vector<Aws::String>& value) { SetEventCategories(value); return *this;}

    /**
     * <p>A list of event categories for a source type (<code>SourceType</code>) that
     * you want to subscribe to. You can see a list of the categories for a given
     * source type in <a
     * href="https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * in the <i>Amazon RDS User Guide</i> or by using the
     * <code>DescribeEventCategories</code> operation.</p>
     */
    inline ModifyEventSubscriptionRequest& WithEventCategories(Aws::Vector<Aws::String>&& value) { SetEventCategories(std::move(value)); return *this;}

    /**
     * <p>A list of event categories for a source type (<code>SourceType</code>) that
     * you want to subscribe to. You can see a list of the categories for a given
     * source type in <a
     * href="https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * in the <i>Amazon RDS User Guide</i> or by using the
     * <code>DescribeEventCategories</code> operation.</p>
     */
    inline ModifyEventSubscriptionRequest& AddEventCategories(const Aws::String& value) { m_eventCategoriesHasBeenSet = true; m_eventCategories.push_back(value); return *this; }

    /**
     * <p>A list of event categories for a source type (<code>SourceType</code>) that
     * you want to subscribe to. You can see a list of the categories for a given
     * source type in <a
     * href="https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * in the <i>Amazon RDS User Guide</i> or by using the
     * <code>DescribeEventCategories</code> operation.</p>
     */
    inline ModifyEventSubscriptionRequest& AddEventCategories(Aws::String&& value) { m_eventCategoriesHasBeenSet = true; m_eventCategories.push_back(std::move(value)); return *this; }

    /**
     * <p>A list of event categories for a source type (<code>SourceType</code>) that
     * you want to subscribe to. You can see a list of the categories for a given
     * source type in <a
     * href="https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html">Events</a>
     * in the <i>Amazon RDS User Guide</i> or by using the
     * <code>DescribeEventCategories</code> operation.</p>
     */
    inline ModifyEventSubscriptionRequest& AddEventCategories(const char* value) { m_eventCategoriesHasBeenSet = true; m_eventCategories.push_back(value); return *this; }


    /**
     * <p>A value that indicates whether to activate the subscription.</p>
     */
    inline bool GetEnabled() const{ return m_enabled; }

    /**
     * <p>A value that indicates whether to activate the subscription.</p>
     */
    inline bool EnabledHasBeenSet() const { return m_enabledHasBeenSet; }

    /**
     * <p>A value that indicates whether to activate the subscription.</p>
     */
    inline void SetEnabled(bool value) { m_enabledHasBeenSet = true; m_enabled = value; }

    /**
     * <p>A value that indicates whether to activate the subscription.</p>
     */
    inline ModifyEventSubscriptionRequest& WithEnabled(bool value) { SetEnabled(value); return *this;}

  private:

    Aws::String m_subscriptionName;
    bool m_subscriptionNameHasBeenSet = false;

    Aws::String m_snsTopicArn;
    bool m_snsTopicArnHasBeenSet = false;

    Aws::String m_sourceType;
    bool m_sourceTypeHasBeenSet = false;

    Aws::Vector<Aws::String> m_eventCategories;
    bool m_eventCategoriesHasBeenSet = false;

    bool m_enabled;
    bool m_enabledHasBeenSet = false;
  };

} // namespace Model
} // namespace RDS
} // namespace Aws
