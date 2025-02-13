﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/opensearch/OpenSearchService_EXPORTS.h>
#include <aws/opensearch/OpenSearchServiceRequest.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/opensearch/model/Filter.h>
#include <utility>

namespace Aws
{
namespace OpenSearchService
{
namespace Model
{

  /**
   * <p>Container for the parameters to the <code> <a>DescribeOutboundConnections</a>
   * </code> operation. </p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/opensearch-2021-01-01/DescribeOutboundConnectionsRequest">AWS
   * API Reference</a></p>
   */
  class AWS_OPENSEARCHSERVICE_API DescribeOutboundConnectionsRequest : public OpenSearchServiceRequest
  {
  public:
    DescribeOutboundConnectionsRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DescribeOutboundConnections"; }

    Aws::String SerializePayload() const override;


    /**
     * <p> A list of filters used to match properties for outbound cross-cluster
     * connections. Available <code> <a>Filter</a> </code> names for this operation
     * are: <ul> <li>connection-id</li> <li>remote-domain-info.domain-name</li>
     * <li>remote-domain-info.owner-id</li> <li>remote-domain-info.region</li>
     * <li>local-domain-info.domain-name</li> </ul> </p>
     */
    inline const Aws::Vector<Filter>& GetFilters() const{ return m_filters; }

    /**
     * <p> A list of filters used to match properties for outbound cross-cluster
     * connections. Available <code> <a>Filter</a> </code> names for this operation
     * are: <ul> <li>connection-id</li> <li>remote-domain-info.domain-name</li>
     * <li>remote-domain-info.owner-id</li> <li>remote-domain-info.region</li>
     * <li>local-domain-info.domain-name</li> </ul> </p>
     */
    inline bool FiltersHasBeenSet() const { return m_filtersHasBeenSet; }

    /**
     * <p> A list of filters used to match properties for outbound cross-cluster
     * connections. Available <code> <a>Filter</a> </code> names for this operation
     * are: <ul> <li>connection-id</li> <li>remote-domain-info.domain-name</li>
     * <li>remote-domain-info.owner-id</li> <li>remote-domain-info.region</li>
     * <li>local-domain-info.domain-name</li> </ul> </p>
     */
    inline void SetFilters(const Aws::Vector<Filter>& value) { m_filtersHasBeenSet = true; m_filters = value; }

    /**
     * <p> A list of filters used to match properties for outbound cross-cluster
     * connections. Available <code> <a>Filter</a> </code> names for this operation
     * are: <ul> <li>connection-id</li> <li>remote-domain-info.domain-name</li>
     * <li>remote-domain-info.owner-id</li> <li>remote-domain-info.region</li>
     * <li>local-domain-info.domain-name</li> </ul> </p>
     */
    inline void SetFilters(Aws::Vector<Filter>&& value) { m_filtersHasBeenSet = true; m_filters = std::move(value); }

    /**
     * <p> A list of filters used to match properties for outbound cross-cluster
     * connections. Available <code> <a>Filter</a> </code> names for this operation
     * are: <ul> <li>connection-id</li> <li>remote-domain-info.domain-name</li>
     * <li>remote-domain-info.owner-id</li> <li>remote-domain-info.region</li>
     * <li>local-domain-info.domain-name</li> </ul> </p>
     */
    inline DescribeOutboundConnectionsRequest& WithFilters(const Aws::Vector<Filter>& value) { SetFilters(value); return *this;}

    /**
     * <p> A list of filters used to match properties for outbound cross-cluster
     * connections. Available <code> <a>Filter</a> </code> names for this operation
     * are: <ul> <li>connection-id</li> <li>remote-domain-info.domain-name</li>
     * <li>remote-domain-info.owner-id</li> <li>remote-domain-info.region</li>
     * <li>local-domain-info.domain-name</li> </ul> </p>
     */
    inline DescribeOutboundConnectionsRequest& WithFilters(Aws::Vector<Filter>&& value) { SetFilters(std::move(value)); return *this;}

    /**
     * <p> A list of filters used to match properties for outbound cross-cluster
     * connections. Available <code> <a>Filter</a> </code> names for this operation
     * are: <ul> <li>connection-id</li> <li>remote-domain-info.domain-name</li>
     * <li>remote-domain-info.owner-id</li> <li>remote-domain-info.region</li>
     * <li>local-domain-info.domain-name</li> </ul> </p>
     */
    inline DescribeOutboundConnectionsRequest& AddFilters(const Filter& value) { m_filtersHasBeenSet = true; m_filters.push_back(value); return *this; }

    /**
     * <p> A list of filters used to match properties for outbound cross-cluster
     * connections. Available <code> <a>Filter</a> </code> names for this operation
     * are: <ul> <li>connection-id</li> <li>remote-domain-info.domain-name</li>
     * <li>remote-domain-info.owner-id</li> <li>remote-domain-info.region</li>
     * <li>local-domain-info.domain-name</li> </ul> </p>
     */
    inline DescribeOutboundConnectionsRequest& AddFilters(Filter&& value) { m_filtersHasBeenSet = true; m_filters.push_back(std::move(value)); return *this; }


    /**
     * <p>Set this value to limit the number of results returned. If not specified,
     * defaults to 100.</p>
     */
    inline int GetMaxResults() const{ return m_maxResults; }

    /**
     * <p>Set this value to limit the number of results returned. If not specified,
     * defaults to 100.</p>
     */
    inline bool MaxResultsHasBeenSet() const { return m_maxResultsHasBeenSet; }

    /**
     * <p>Set this value to limit the number of results returned. If not specified,
     * defaults to 100.</p>
     */
    inline void SetMaxResults(int value) { m_maxResultsHasBeenSet = true; m_maxResults = value; }

    /**
     * <p>Set this value to limit the number of results returned. If not specified,
     * defaults to 100.</p>
     */
    inline DescribeOutboundConnectionsRequest& WithMaxResults(int value) { SetMaxResults(value); return *this;}


    /**
     * <p>NextToken is sent in case the earlier API call results contain the NextToken
     * parameter. Used for pagination.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>NextToken is sent in case the earlier API call results contain the NextToken
     * parameter. Used for pagination.</p>
     */
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }

    /**
     * <p>NextToken is sent in case the earlier API call results contain the NextToken
     * parameter. Used for pagination.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    /**
     * <p>NextToken is sent in case the earlier API call results contain the NextToken
     * parameter. Used for pagination.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }

    /**
     * <p>NextToken is sent in case the earlier API call results contain the NextToken
     * parameter. Used for pagination.</p>
     */
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    /**
     * <p>NextToken is sent in case the earlier API call results contain the NextToken
     * parameter. Used for pagination.</p>
     */
    inline DescribeOutboundConnectionsRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>NextToken is sent in case the earlier API call results contain the NextToken
     * parameter. Used for pagination.</p>
     */
    inline DescribeOutboundConnectionsRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>NextToken is sent in case the earlier API call results contain the NextToken
     * parameter. Used for pagination.</p>
     */
    inline DescribeOutboundConnectionsRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}

  private:

    Aws::Vector<Filter> m_filters;
    bool m_filtersHasBeenSet = false;

    int m_maxResults;
    bool m_maxResultsHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;
  };

} // namespace Model
} // namespace OpenSearchService
} // namespace Aws
