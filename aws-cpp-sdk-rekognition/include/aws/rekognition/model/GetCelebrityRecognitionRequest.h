﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/rekognition/Rekognition_EXPORTS.h>
#include <aws/rekognition/RekognitionRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/rekognition/model/CelebrityRecognitionSortBy.h>
#include <utility>

namespace Aws
{
namespace Rekognition
{
namespace Model
{

  /**
   */
  class AWS_REKOGNITION_API GetCelebrityRecognitionRequest : public RekognitionRequest
  {
  public:
    GetCelebrityRecognitionRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "GetCelebrityRecognition"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>Job identifier for the required celebrity recognition analysis. You can get
     * the job identifer from a call to <code>StartCelebrityRecognition</code>.</p>
     */
    inline const Aws::String& GetJobId() const{ return m_jobId; }

    /**
     * <p>Job identifier for the required celebrity recognition analysis. You can get
     * the job identifer from a call to <code>StartCelebrityRecognition</code>.</p>
     */
    inline bool JobIdHasBeenSet() const { return m_jobIdHasBeenSet; }

    /**
     * <p>Job identifier for the required celebrity recognition analysis. You can get
     * the job identifer from a call to <code>StartCelebrityRecognition</code>.</p>
     */
    inline void SetJobId(const Aws::String& value) { m_jobIdHasBeenSet = true; m_jobId = value; }

    /**
     * <p>Job identifier for the required celebrity recognition analysis. You can get
     * the job identifer from a call to <code>StartCelebrityRecognition</code>.</p>
     */
    inline void SetJobId(Aws::String&& value) { m_jobIdHasBeenSet = true; m_jobId = std::move(value); }

    /**
     * <p>Job identifier for the required celebrity recognition analysis. You can get
     * the job identifer from a call to <code>StartCelebrityRecognition</code>.</p>
     */
    inline void SetJobId(const char* value) { m_jobIdHasBeenSet = true; m_jobId.assign(value); }

    /**
     * <p>Job identifier for the required celebrity recognition analysis. You can get
     * the job identifer from a call to <code>StartCelebrityRecognition</code>.</p>
     */
    inline GetCelebrityRecognitionRequest& WithJobId(const Aws::String& value) { SetJobId(value); return *this;}

    /**
     * <p>Job identifier for the required celebrity recognition analysis. You can get
     * the job identifer from a call to <code>StartCelebrityRecognition</code>.</p>
     */
    inline GetCelebrityRecognitionRequest& WithJobId(Aws::String&& value) { SetJobId(std::move(value)); return *this;}

    /**
     * <p>Job identifier for the required celebrity recognition analysis. You can get
     * the job identifer from a call to <code>StartCelebrityRecognition</code>.</p>
     */
    inline GetCelebrityRecognitionRequest& WithJobId(const char* value) { SetJobId(value); return *this;}


    /**
     * <p>Maximum number of results to return per paginated call. The largest value you
     * can specify is 1000. If you specify a value greater than 1000, a maximum of 1000
     * results is returned. The default value is 1000.</p>
     */
    inline int GetMaxResults() const{ return m_maxResults; }

    /**
     * <p>Maximum number of results to return per paginated call. The largest value you
     * can specify is 1000. If you specify a value greater than 1000, a maximum of 1000
     * results is returned. The default value is 1000.</p>
     */
    inline bool MaxResultsHasBeenSet() const { return m_maxResultsHasBeenSet; }

    /**
     * <p>Maximum number of results to return per paginated call. The largest value you
     * can specify is 1000. If you specify a value greater than 1000, a maximum of 1000
     * results is returned. The default value is 1000.</p>
     */
    inline void SetMaxResults(int value) { m_maxResultsHasBeenSet = true; m_maxResults = value; }

    /**
     * <p>Maximum number of results to return per paginated call. The largest value you
     * can specify is 1000. If you specify a value greater than 1000, a maximum of 1000
     * results is returned. The default value is 1000.</p>
     */
    inline GetCelebrityRecognitionRequest& WithMaxResults(int value) { SetMaxResults(value); return *this;}


    /**
     * <p>If the previous response was incomplete (because there is more recognized
     * celebrities to retrieve), Amazon Rekognition Video returns a pagination token in
     * the response. You can use this pagination token to retrieve the next set of
     * celebrities. </p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>If the previous response was incomplete (because there is more recognized
     * celebrities to retrieve), Amazon Rekognition Video returns a pagination token in
     * the response. You can use this pagination token to retrieve the next set of
     * celebrities. </p>
     */
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }

    /**
     * <p>If the previous response was incomplete (because there is more recognized
     * celebrities to retrieve), Amazon Rekognition Video returns a pagination token in
     * the response. You can use this pagination token to retrieve the next set of
     * celebrities. </p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    /**
     * <p>If the previous response was incomplete (because there is more recognized
     * celebrities to retrieve), Amazon Rekognition Video returns a pagination token in
     * the response. You can use this pagination token to retrieve the next set of
     * celebrities. </p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }

    /**
     * <p>If the previous response was incomplete (because there is more recognized
     * celebrities to retrieve), Amazon Rekognition Video returns a pagination token in
     * the response. You can use this pagination token to retrieve the next set of
     * celebrities. </p>
     */
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    /**
     * <p>If the previous response was incomplete (because there is more recognized
     * celebrities to retrieve), Amazon Rekognition Video returns a pagination token in
     * the response. You can use this pagination token to retrieve the next set of
     * celebrities. </p>
     */
    inline GetCelebrityRecognitionRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>If the previous response was incomplete (because there is more recognized
     * celebrities to retrieve), Amazon Rekognition Video returns a pagination token in
     * the response. You can use this pagination token to retrieve the next set of
     * celebrities. </p>
     */
    inline GetCelebrityRecognitionRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>If the previous response was incomplete (because there is more recognized
     * celebrities to retrieve), Amazon Rekognition Video returns a pagination token in
     * the response. You can use this pagination token to retrieve the next set of
     * celebrities. </p>
     */
    inline GetCelebrityRecognitionRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}


    /**
     * <p>Sort to use for celebrities returned in <code>Celebrities</code> field.
     * Specify <code>ID</code> to sort by the celebrity identifier, specify
     * <code>TIMESTAMP</code> to sort by the time the celebrity was recognized.</p>
     */
    inline const CelebrityRecognitionSortBy& GetSortBy() const{ return m_sortBy; }

    /**
     * <p>Sort to use for celebrities returned in <code>Celebrities</code> field.
     * Specify <code>ID</code> to sort by the celebrity identifier, specify
     * <code>TIMESTAMP</code> to sort by the time the celebrity was recognized.</p>
     */
    inline bool SortByHasBeenSet() const { return m_sortByHasBeenSet; }

    /**
     * <p>Sort to use for celebrities returned in <code>Celebrities</code> field.
     * Specify <code>ID</code> to sort by the celebrity identifier, specify
     * <code>TIMESTAMP</code> to sort by the time the celebrity was recognized.</p>
     */
    inline void SetSortBy(const CelebrityRecognitionSortBy& value) { m_sortByHasBeenSet = true; m_sortBy = value; }

    /**
     * <p>Sort to use for celebrities returned in <code>Celebrities</code> field.
     * Specify <code>ID</code> to sort by the celebrity identifier, specify
     * <code>TIMESTAMP</code> to sort by the time the celebrity was recognized.</p>
     */
    inline void SetSortBy(CelebrityRecognitionSortBy&& value) { m_sortByHasBeenSet = true; m_sortBy = std::move(value); }

    /**
     * <p>Sort to use for celebrities returned in <code>Celebrities</code> field.
     * Specify <code>ID</code> to sort by the celebrity identifier, specify
     * <code>TIMESTAMP</code> to sort by the time the celebrity was recognized.</p>
     */
    inline GetCelebrityRecognitionRequest& WithSortBy(const CelebrityRecognitionSortBy& value) { SetSortBy(value); return *this;}

    /**
     * <p>Sort to use for celebrities returned in <code>Celebrities</code> field.
     * Specify <code>ID</code> to sort by the celebrity identifier, specify
     * <code>TIMESTAMP</code> to sort by the time the celebrity was recognized.</p>
     */
    inline GetCelebrityRecognitionRequest& WithSortBy(CelebrityRecognitionSortBy&& value) { SetSortBy(std::move(value)); return *this;}

  private:

    Aws::String m_jobId;
    bool m_jobIdHasBeenSet = false;

    int m_maxResults;
    bool m_maxResultsHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;

    CelebrityRecognitionSortBy m_sortBy;
    bool m_sortByHasBeenSet = false;
  };

} // namespace Model
} // namespace Rekognition
} // namespace Aws
