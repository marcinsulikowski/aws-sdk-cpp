﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/iotsitewise/IoTSiteWise_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/iotsitewise/model/BatchEntryCompletionStatus.h>
#include <aws/iotsitewise/model/BatchGetAssetPropertyAggregatesErrorInfo.h>
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
namespace IoTSiteWise
{
namespace Model
{

  /**
   * <p>Contains information for an entry that has been processed by the previous <a
   * href="https://docs.aws.amazon.com/iot-sitewise/latest/APIReference/API_BatchGetAssetPropertyAggregates.html">BatchGetAssetPropertyAggregates</a>
   * request.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/iotsitewise-2019-12-02/BatchGetAssetPropertyAggregatesSkippedEntry">AWS
   * API Reference</a></p>
   */
  class AWS_IOTSITEWISE_API BatchGetAssetPropertyAggregatesSkippedEntry
  {
  public:
    BatchGetAssetPropertyAggregatesSkippedEntry();
    BatchGetAssetPropertyAggregatesSkippedEntry(Aws::Utils::Json::JsonView jsonValue);
    BatchGetAssetPropertyAggregatesSkippedEntry& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The ID of the entry.</p>
     */
    inline const Aws::String& GetEntryId() const{ return m_entryId; }

    /**
     * <p>The ID of the entry.</p>
     */
    inline bool EntryIdHasBeenSet() const { return m_entryIdHasBeenSet; }

    /**
     * <p>The ID of the entry.</p>
     */
    inline void SetEntryId(const Aws::String& value) { m_entryIdHasBeenSet = true; m_entryId = value; }

    /**
     * <p>The ID of the entry.</p>
     */
    inline void SetEntryId(Aws::String&& value) { m_entryIdHasBeenSet = true; m_entryId = std::move(value); }

    /**
     * <p>The ID of the entry.</p>
     */
    inline void SetEntryId(const char* value) { m_entryIdHasBeenSet = true; m_entryId.assign(value); }

    /**
     * <p>The ID of the entry.</p>
     */
    inline BatchGetAssetPropertyAggregatesSkippedEntry& WithEntryId(const Aws::String& value) { SetEntryId(value); return *this;}

    /**
     * <p>The ID of the entry.</p>
     */
    inline BatchGetAssetPropertyAggregatesSkippedEntry& WithEntryId(Aws::String&& value) { SetEntryId(std::move(value)); return *this;}

    /**
     * <p>The ID of the entry.</p>
     */
    inline BatchGetAssetPropertyAggregatesSkippedEntry& WithEntryId(const char* value) { SetEntryId(value); return *this;}


    /**
     * <p>The completion status of each entry that is associated with the <a
     * href="https://docs.aws.amazon.com/iot-sitewise/latest/APIReference/API_BatchGetAssetPropertyAggregates.html">BatchGetAssetPropertyAggregates</a>
     * API.</p>
     */
    inline const BatchEntryCompletionStatus& GetCompletionStatus() const{ return m_completionStatus; }

    /**
     * <p>The completion status of each entry that is associated with the <a
     * href="https://docs.aws.amazon.com/iot-sitewise/latest/APIReference/API_BatchGetAssetPropertyAggregates.html">BatchGetAssetPropertyAggregates</a>
     * API.</p>
     */
    inline bool CompletionStatusHasBeenSet() const { return m_completionStatusHasBeenSet; }

    /**
     * <p>The completion status of each entry that is associated with the <a
     * href="https://docs.aws.amazon.com/iot-sitewise/latest/APIReference/API_BatchGetAssetPropertyAggregates.html">BatchGetAssetPropertyAggregates</a>
     * API.</p>
     */
    inline void SetCompletionStatus(const BatchEntryCompletionStatus& value) { m_completionStatusHasBeenSet = true; m_completionStatus = value; }

    /**
     * <p>The completion status of each entry that is associated with the <a
     * href="https://docs.aws.amazon.com/iot-sitewise/latest/APIReference/API_BatchGetAssetPropertyAggregates.html">BatchGetAssetPropertyAggregates</a>
     * API.</p>
     */
    inline void SetCompletionStatus(BatchEntryCompletionStatus&& value) { m_completionStatusHasBeenSet = true; m_completionStatus = std::move(value); }

    /**
     * <p>The completion status of each entry that is associated with the <a
     * href="https://docs.aws.amazon.com/iot-sitewise/latest/APIReference/API_BatchGetAssetPropertyAggregates.html">BatchGetAssetPropertyAggregates</a>
     * API.</p>
     */
    inline BatchGetAssetPropertyAggregatesSkippedEntry& WithCompletionStatus(const BatchEntryCompletionStatus& value) { SetCompletionStatus(value); return *this;}

    /**
     * <p>The completion status of each entry that is associated with the <a
     * href="https://docs.aws.amazon.com/iot-sitewise/latest/APIReference/API_BatchGetAssetPropertyAggregates.html">BatchGetAssetPropertyAggregates</a>
     * API.</p>
     */
    inline BatchGetAssetPropertyAggregatesSkippedEntry& WithCompletionStatus(BatchEntryCompletionStatus&& value) { SetCompletionStatus(std::move(value)); return *this;}


    /**
     * <p>The error information, such as the error code and the timestamp.</p>
     */
    inline const BatchGetAssetPropertyAggregatesErrorInfo& GetErrorInfo() const{ return m_errorInfo; }

    /**
     * <p>The error information, such as the error code and the timestamp.</p>
     */
    inline bool ErrorInfoHasBeenSet() const { return m_errorInfoHasBeenSet; }

    /**
     * <p>The error information, such as the error code and the timestamp.</p>
     */
    inline void SetErrorInfo(const BatchGetAssetPropertyAggregatesErrorInfo& value) { m_errorInfoHasBeenSet = true; m_errorInfo = value; }

    /**
     * <p>The error information, such as the error code and the timestamp.</p>
     */
    inline void SetErrorInfo(BatchGetAssetPropertyAggregatesErrorInfo&& value) { m_errorInfoHasBeenSet = true; m_errorInfo = std::move(value); }

    /**
     * <p>The error information, such as the error code and the timestamp.</p>
     */
    inline BatchGetAssetPropertyAggregatesSkippedEntry& WithErrorInfo(const BatchGetAssetPropertyAggregatesErrorInfo& value) { SetErrorInfo(value); return *this;}

    /**
     * <p>The error information, such as the error code and the timestamp.</p>
     */
    inline BatchGetAssetPropertyAggregatesSkippedEntry& WithErrorInfo(BatchGetAssetPropertyAggregatesErrorInfo&& value) { SetErrorInfo(std::move(value)); return *this;}

  private:

    Aws::String m_entryId;
    bool m_entryIdHasBeenSet = false;

    BatchEntryCompletionStatus m_completionStatus;
    bool m_completionStatusHasBeenSet = false;

    BatchGetAssetPropertyAggregatesErrorInfo m_errorInfo;
    bool m_errorInfoHasBeenSet = false;
  };

} // namespace Model
} // namespace IoTSiteWise
} // namespace Aws
