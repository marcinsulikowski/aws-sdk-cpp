﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/logs/CloudWatchLogs_EXPORTS.h>
#include <aws/logs/CloudWatchLogsRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace CloudWatchLogs
{
namespace Model
{

  /**
   */
  class AWS_CLOUDWATCHLOGS_API GetLogEventsRequest : public CloudWatchLogsRequest
  {
  public:
    GetLogEventsRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "GetLogEvents"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The name of the log group.</p>
     */
    inline const Aws::String& GetLogGroupName() const{ return m_logGroupName; }

    /**
     * <p>The name of the log group.</p>
     */
    inline bool LogGroupNameHasBeenSet() const { return m_logGroupNameHasBeenSet; }

    /**
     * <p>The name of the log group.</p>
     */
    inline void SetLogGroupName(const Aws::String& value) { m_logGroupNameHasBeenSet = true; m_logGroupName = value; }

    /**
     * <p>The name of the log group.</p>
     */
    inline void SetLogGroupName(Aws::String&& value) { m_logGroupNameHasBeenSet = true; m_logGroupName = std::move(value); }

    /**
     * <p>The name of the log group.</p>
     */
    inline void SetLogGroupName(const char* value) { m_logGroupNameHasBeenSet = true; m_logGroupName.assign(value); }

    /**
     * <p>The name of the log group.</p>
     */
    inline GetLogEventsRequest& WithLogGroupName(const Aws::String& value) { SetLogGroupName(value); return *this;}

    /**
     * <p>The name of the log group.</p>
     */
    inline GetLogEventsRequest& WithLogGroupName(Aws::String&& value) { SetLogGroupName(std::move(value)); return *this;}

    /**
     * <p>The name of the log group.</p>
     */
    inline GetLogEventsRequest& WithLogGroupName(const char* value) { SetLogGroupName(value); return *this;}


    /**
     * <p>The name of the log stream.</p>
     */
    inline const Aws::String& GetLogStreamName() const{ return m_logStreamName; }

    /**
     * <p>The name of the log stream.</p>
     */
    inline bool LogStreamNameHasBeenSet() const { return m_logStreamNameHasBeenSet; }

    /**
     * <p>The name of the log stream.</p>
     */
    inline void SetLogStreamName(const Aws::String& value) { m_logStreamNameHasBeenSet = true; m_logStreamName = value; }

    /**
     * <p>The name of the log stream.</p>
     */
    inline void SetLogStreamName(Aws::String&& value) { m_logStreamNameHasBeenSet = true; m_logStreamName = std::move(value); }

    /**
     * <p>The name of the log stream.</p>
     */
    inline void SetLogStreamName(const char* value) { m_logStreamNameHasBeenSet = true; m_logStreamName.assign(value); }

    /**
     * <p>The name of the log stream.</p>
     */
    inline GetLogEventsRequest& WithLogStreamName(const Aws::String& value) { SetLogStreamName(value); return *this;}

    /**
     * <p>The name of the log stream.</p>
     */
    inline GetLogEventsRequest& WithLogStreamName(Aws::String&& value) { SetLogStreamName(std::move(value)); return *this;}

    /**
     * <p>The name of the log stream.</p>
     */
    inline GetLogEventsRequest& WithLogStreamName(const char* value) { SetLogStreamName(value); return *this;}


    /**
     * <p>The start of the time range, expressed as the number of milliseconds after
     * Jan 1, 1970 00:00:00 UTC. Events with a timestamp equal to this time or later
     * than this time are included. Events with a timestamp earlier than this time are
     * not included.</p>
     */
    inline long long GetStartTime() const{ return m_startTime; }

    /**
     * <p>The start of the time range, expressed as the number of milliseconds after
     * Jan 1, 1970 00:00:00 UTC. Events with a timestamp equal to this time or later
     * than this time are included. Events with a timestamp earlier than this time are
     * not included.</p>
     */
    inline bool StartTimeHasBeenSet() const { return m_startTimeHasBeenSet; }

    /**
     * <p>The start of the time range, expressed as the number of milliseconds after
     * Jan 1, 1970 00:00:00 UTC. Events with a timestamp equal to this time or later
     * than this time are included. Events with a timestamp earlier than this time are
     * not included.</p>
     */
    inline void SetStartTime(long long value) { m_startTimeHasBeenSet = true; m_startTime = value; }

    /**
     * <p>The start of the time range, expressed as the number of milliseconds after
     * Jan 1, 1970 00:00:00 UTC. Events with a timestamp equal to this time or later
     * than this time are included. Events with a timestamp earlier than this time are
     * not included.</p>
     */
    inline GetLogEventsRequest& WithStartTime(long long value) { SetStartTime(value); return *this;}


    /**
     * <p>The end of the time range, expressed as the number of milliseconds after Jan
     * 1, 1970 00:00:00 UTC. Events with a timestamp equal to or later than this time
     * are not included.</p>
     */
    inline long long GetEndTime() const{ return m_endTime; }

    /**
     * <p>The end of the time range, expressed as the number of milliseconds after Jan
     * 1, 1970 00:00:00 UTC. Events with a timestamp equal to or later than this time
     * are not included.</p>
     */
    inline bool EndTimeHasBeenSet() const { return m_endTimeHasBeenSet; }

    /**
     * <p>The end of the time range, expressed as the number of milliseconds after Jan
     * 1, 1970 00:00:00 UTC. Events with a timestamp equal to or later than this time
     * are not included.</p>
     */
    inline void SetEndTime(long long value) { m_endTimeHasBeenSet = true; m_endTime = value; }

    /**
     * <p>The end of the time range, expressed as the number of milliseconds after Jan
     * 1, 1970 00:00:00 UTC. Events with a timestamp equal to or later than this time
     * are not included.</p>
     */
    inline GetLogEventsRequest& WithEndTime(long long value) { SetEndTime(value); return *this;}


    /**
     * <p>The token for the next set of items to return. (You received this token from
     * a previous call.)</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>The token for the next set of items to return. (You received this token from
     * a previous call.)</p>
     */
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }

    /**
     * <p>The token for the next set of items to return. (You received this token from
     * a previous call.)</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    /**
     * <p>The token for the next set of items to return. (You received this token from
     * a previous call.)</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }

    /**
     * <p>The token for the next set of items to return. (You received this token from
     * a previous call.)</p>
     */
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    /**
     * <p>The token for the next set of items to return. (You received this token from
     * a previous call.)</p>
     */
    inline GetLogEventsRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>The token for the next set of items to return. (You received this token from
     * a previous call.)</p>
     */
    inline GetLogEventsRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>The token for the next set of items to return. (You received this token from
     * a previous call.)</p>
     */
    inline GetLogEventsRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}


    /**
     * <p>The maximum number of log events returned. If you don't specify a value, the
     * maximum is as many log events as can fit in a response size of 1 MB, up to
     * 10,000 log events.</p>
     */
    inline int GetLimit() const{ return m_limit; }

    /**
     * <p>The maximum number of log events returned. If you don't specify a value, the
     * maximum is as many log events as can fit in a response size of 1 MB, up to
     * 10,000 log events.</p>
     */
    inline bool LimitHasBeenSet() const { return m_limitHasBeenSet; }

    /**
     * <p>The maximum number of log events returned. If you don't specify a value, the
     * maximum is as many log events as can fit in a response size of 1 MB, up to
     * 10,000 log events.</p>
     */
    inline void SetLimit(int value) { m_limitHasBeenSet = true; m_limit = value; }

    /**
     * <p>The maximum number of log events returned. If you don't specify a value, the
     * maximum is as many log events as can fit in a response size of 1 MB, up to
     * 10,000 log events.</p>
     */
    inline GetLogEventsRequest& WithLimit(int value) { SetLimit(value); return *this;}


    /**
     * <p>If the value is true, the earliest log events are returned first. If the
     * value is false, the latest log events are returned first. The default value is
     * false.</p> <p>If you are using a previous <code>nextForwardToken</code> value as
     * the <code>nextToken</code> in this operation, you must specify <code>true</code>
     * for <code>startFromHead</code>.</p>
     */
    inline bool GetStartFromHead() const{ return m_startFromHead; }

    /**
     * <p>If the value is true, the earliest log events are returned first. If the
     * value is false, the latest log events are returned first. The default value is
     * false.</p> <p>If you are using a previous <code>nextForwardToken</code> value as
     * the <code>nextToken</code> in this operation, you must specify <code>true</code>
     * for <code>startFromHead</code>.</p>
     */
    inline bool StartFromHeadHasBeenSet() const { return m_startFromHeadHasBeenSet; }

    /**
     * <p>If the value is true, the earliest log events are returned first. If the
     * value is false, the latest log events are returned first. The default value is
     * false.</p> <p>If you are using a previous <code>nextForwardToken</code> value as
     * the <code>nextToken</code> in this operation, you must specify <code>true</code>
     * for <code>startFromHead</code>.</p>
     */
    inline void SetStartFromHead(bool value) { m_startFromHeadHasBeenSet = true; m_startFromHead = value; }

    /**
     * <p>If the value is true, the earliest log events are returned first. If the
     * value is false, the latest log events are returned first. The default value is
     * false.</p> <p>If you are using a previous <code>nextForwardToken</code> value as
     * the <code>nextToken</code> in this operation, you must specify <code>true</code>
     * for <code>startFromHead</code>.</p>
     */
    inline GetLogEventsRequest& WithStartFromHead(bool value) { SetStartFromHead(value); return *this;}

  private:

    Aws::String m_logGroupName;
    bool m_logGroupNameHasBeenSet = false;

    Aws::String m_logStreamName;
    bool m_logStreamNameHasBeenSet = false;

    long long m_startTime;
    bool m_startTimeHasBeenSet = false;

    long long m_endTime;
    bool m_endTimeHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;

    int m_limit;
    bool m_limitHasBeenSet = false;

    bool m_startFromHead;
    bool m_startFromHeadHasBeenSet = false;
  };

} // namespace Model
} // namespace CloudWatchLogs
} // namespace Aws
