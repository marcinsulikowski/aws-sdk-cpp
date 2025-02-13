﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/pinpoint-sms-voice-v2/PinpointSMSVoiceV2_EXPORTS.h>
#include <aws/pinpoint-sms-voice-v2/PinpointSMSVoiceV2Request.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace PinpointSMSVoiceV2
{
namespace Model
{

  /**
   */
  class AWS_PINPOINTSMSVOICEV2_API DescribeOptOutListsRequest : public PinpointSMSVoiceV2Request
  {
  public:
    DescribeOptOutListsRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DescribeOptOutLists"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The OptOutLists to show the details of. This is an array of strings that can
     * be either the OptOutListName or OptOutListArn.</p>
     */
    inline const Aws::Vector<Aws::String>& GetOptOutListNames() const{ return m_optOutListNames; }

    /**
     * <p>The OptOutLists to show the details of. This is an array of strings that can
     * be either the OptOutListName or OptOutListArn.</p>
     */
    inline bool OptOutListNamesHasBeenSet() const { return m_optOutListNamesHasBeenSet; }

    /**
     * <p>The OptOutLists to show the details of. This is an array of strings that can
     * be either the OptOutListName or OptOutListArn.</p>
     */
    inline void SetOptOutListNames(const Aws::Vector<Aws::String>& value) { m_optOutListNamesHasBeenSet = true; m_optOutListNames = value; }

    /**
     * <p>The OptOutLists to show the details of. This is an array of strings that can
     * be either the OptOutListName or OptOutListArn.</p>
     */
    inline void SetOptOutListNames(Aws::Vector<Aws::String>&& value) { m_optOutListNamesHasBeenSet = true; m_optOutListNames = std::move(value); }

    /**
     * <p>The OptOutLists to show the details of. This is an array of strings that can
     * be either the OptOutListName or OptOutListArn.</p>
     */
    inline DescribeOptOutListsRequest& WithOptOutListNames(const Aws::Vector<Aws::String>& value) { SetOptOutListNames(value); return *this;}

    /**
     * <p>The OptOutLists to show the details of. This is an array of strings that can
     * be either the OptOutListName or OptOutListArn.</p>
     */
    inline DescribeOptOutListsRequest& WithOptOutListNames(Aws::Vector<Aws::String>&& value) { SetOptOutListNames(std::move(value)); return *this;}

    /**
     * <p>The OptOutLists to show the details of. This is an array of strings that can
     * be either the OptOutListName or OptOutListArn.</p>
     */
    inline DescribeOptOutListsRequest& AddOptOutListNames(const Aws::String& value) { m_optOutListNamesHasBeenSet = true; m_optOutListNames.push_back(value); return *this; }

    /**
     * <p>The OptOutLists to show the details of. This is an array of strings that can
     * be either the OptOutListName or OptOutListArn.</p>
     */
    inline DescribeOptOutListsRequest& AddOptOutListNames(Aws::String&& value) { m_optOutListNamesHasBeenSet = true; m_optOutListNames.push_back(std::move(value)); return *this; }

    /**
     * <p>The OptOutLists to show the details of. This is an array of strings that can
     * be either the OptOutListName or OptOutListArn.</p>
     */
    inline DescribeOptOutListsRequest& AddOptOutListNames(const char* value) { m_optOutListNamesHasBeenSet = true; m_optOutListNames.push_back(value); return *this; }


    /**
     * <p>The token to be used for the next set of paginated results. You don't need to
     * supply a value for this field in the initial request.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>The token to be used for the next set of paginated results. You don't need to
     * supply a value for this field in the initial request.</p>
     */
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }

    /**
     * <p>The token to be used for the next set of paginated results. You don't need to
     * supply a value for this field in the initial request.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    /**
     * <p>The token to be used for the next set of paginated results. You don't need to
     * supply a value for this field in the initial request.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }

    /**
     * <p>The token to be used for the next set of paginated results. You don't need to
     * supply a value for this field in the initial request.</p>
     */
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    /**
     * <p>The token to be used for the next set of paginated results. You don't need to
     * supply a value for this field in the initial request.</p>
     */
    inline DescribeOptOutListsRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>The token to be used for the next set of paginated results. You don't need to
     * supply a value for this field in the initial request.</p>
     */
    inline DescribeOptOutListsRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>The token to be used for the next set of paginated results. You don't need to
     * supply a value for this field in the initial request.</p>
     */
    inline DescribeOptOutListsRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}


    /**
     * <p>The maximum number of results to return per each request.</p>
     */
    inline int GetMaxResults() const{ return m_maxResults; }

    /**
     * <p>The maximum number of results to return per each request.</p>
     */
    inline bool MaxResultsHasBeenSet() const { return m_maxResultsHasBeenSet; }

    /**
     * <p>The maximum number of results to return per each request.</p>
     */
    inline void SetMaxResults(int value) { m_maxResultsHasBeenSet = true; m_maxResults = value; }

    /**
     * <p>The maximum number of results to return per each request.</p>
     */
    inline DescribeOptOutListsRequest& WithMaxResults(int value) { SetMaxResults(value); return *this;}

  private:

    Aws::Vector<Aws::String> m_optOutListNames;
    bool m_optOutListNamesHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;

    int m_maxResults;
    bool m_maxResultsHasBeenSet = false;
  };

} // namespace Model
} // namespace PinpointSMSVoiceV2
} // namespace Aws
