﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/docdb/DocDB_EXPORTS.h>
#include <aws/docdb/DocDBRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/docdb/model/Tag.h>
#include <utility>

namespace Aws
{
namespace DocDB
{
namespace Model
{

  /**
   * <p>Represents the input to <a>CopyDBClusterParameterGroup</a>. </p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/docdb-2014-10-31/CopyDBClusterParameterGroupMessage">AWS
   * API Reference</a></p>
   */
  class AWS_DOCDB_API CopyDBClusterParameterGroupRequest : public DocDBRequest
  {
  public:
    CopyDBClusterParameterGroupRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "CopyDBClusterParameterGroup"; }

    Aws::String SerializePayload() const override;

  protected:
    void DumpBodyToUrl(Aws::Http::URI& uri ) const override;

  public:

    /**
     * <p>The identifier or Amazon Resource Name (ARN) for the source cluster parameter
     * group.</p> <p>Constraints:</p> <ul> <li> <p>Must specify a valid cluster
     * parameter group.</p> </li> <li> <p>If the source cluster parameter group is in
     * the same Amazon Web Services Region as the copy, specify a valid parameter group
     * identifier; for example, <code>my-db-cluster-param-group</code>, or a valid
     * ARN.</p> </li> <li> <p>If the source parameter group is in a different Amazon
     * Web Services Region than the copy, specify a valid cluster parameter group ARN;
     * for example,
     * <code>arn:aws:rds:us-east-1:123456789012:sample-cluster:sample-parameter-group</code>.</p>
     * </li> </ul>
     */
    inline const Aws::String& GetSourceDBClusterParameterGroupIdentifier() const{ return m_sourceDBClusterParameterGroupIdentifier; }

    /**
     * <p>The identifier or Amazon Resource Name (ARN) for the source cluster parameter
     * group.</p> <p>Constraints:</p> <ul> <li> <p>Must specify a valid cluster
     * parameter group.</p> </li> <li> <p>If the source cluster parameter group is in
     * the same Amazon Web Services Region as the copy, specify a valid parameter group
     * identifier; for example, <code>my-db-cluster-param-group</code>, or a valid
     * ARN.</p> </li> <li> <p>If the source parameter group is in a different Amazon
     * Web Services Region than the copy, specify a valid cluster parameter group ARN;
     * for example,
     * <code>arn:aws:rds:us-east-1:123456789012:sample-cluster:sample-parameter-group</code>.</p>
     * </li> </ul>
     */
    inline bool SourceDBClusterParameterGroupIdentifierHasBeenSet() const { return m_sourceDBClusterParameterGroupIdentifierHasBeenSet; }

    /**
     * <p>The identifier or Amazon Resource Name (ARN) for the source cluster parameter
     * group.</p> <p>Constraints:</p> <ul> <li> <p>Must specify a valid cluster
     * parameter group.</p> </li> <li> <p>If the source cluster parameter group is in
     * the same Amazon Web Services Region as the copy, specify a valid parameter group
     * identifier; for example, <code>my-db-cluster-param-group</code>, or a valid
     * ARN.</p> </li> <li> <p>If the source parameter group is in a different Amazon
     * Web Services Region than the copy, specify a valid cluster parameter group ARN;
     * for example,
     * <code>arn:aws:rds:us-east-1:123456789012:sample-cluster:sample-parameter-group</code>.</p>
     * </li> </ul>
     */
    inline void SetSourceDBClusterParameterGroupIdentifier(const Aws::String& value) { m_sourceDBClusterParameterGroupIdentifierHasBeenSet = true; m_sourceDBClusterParameterGroupIdentifier = value; }

    /**
     * <p>The identifier or Amazon Resource Name (ARN) for the source cluster parameter
     * group.</p> <p>Constraints:</p> <ul> <li> <p>Must specify a valid cluster
     * parameter group.</p> </li> <li> <p>If the source cluster parameter group is in
     * the same Amazon Web Services Region as the copy, specify a valid parameter group
     * identifier; for example, <code>my-db-cluster-param-group</code>, or a valid
     * ARN.</p> </li> <li> <p>If the source parameter group is in a different Amazon
     * Web Services Region than the copy, specify a valid cluster parameter group ARN;
     * for example,
     * <code>arn:aws:rds:us-east-1:123456789012:sample-cluster:sample-parameter-group</code>.</p>
     * </li> </ul>
     */
    inline void SetSourceDBClusterParameterGroupIdentifier(Aws::String&& value) { m_sourceDBClusterParameterGroupIdentifierHasBeenSet = true; m_sourceDBClusterParameterGroupIdentifier = std::move(value); }

    /**
     * <p>The identifier or Amazon Resource Name (ARN) for the source cluster parameter
     * group.</p> <p>Constraints:</p> <ul> <li> <p>Must specify a valid cluster
     * parameter group.</p> </li> <li> <p>If the source cluster parameter group is in
     * the same Amazon Web Services Region as the copy, specify a valid parameter group
     * identifier; for example, <code>my-db-cluster-param-group</code>, or a valid
     * ARN.</p> </li> <li> <p>If the source parameter group is in a different Amazon
     * Web Services Region than the copy, specify a valid cluster parameter group ARN;
     * for example,
     * <code>arn:aws:rds:us-east-1:123456789012:sample-cluster:sample-parameter-group</code>.</p>
     * </li> </ul>
     */
    inline void SetSourceDBClusterParameterGroupIdentifier(const char* value) { m_sourceDBClusterParameterGroupIdentifierHasBeenSet = true; m_sourceDBClusterParameterGroupIdentifier.assign(value); }

    /**
     * <p>The identifier or Amazon Resource Name (ARN) for the source cluster parameter
     * group.</p> <p>Constraints:</p> <ul> <li> <p>Must specify a valid cluster
     * parameter group.</p> </li> <li> <p>If the source cluster parameter group is in
     * the same Amazon Web Services Region as the copy, specify a valid parameter group
     * identifier; for example, <code>my-db-cluster-param-group</code>, or a valid
     * ARN.</p> </li> <li> <p>If the source parameter group is in a different Amazon
     * Web Services Region than the copy, specify a valid cluster parameter group ARN;
     * for example,
     * <code>arn:aws:rds:us-east-1:123456789012:sample-cluster:sample-parameter-group</code>.</p>
     * </li> </ul>
     */
    inline CopyDBClusterParameterGroupRequest& WithSourceDBClusterParameterGroupIdentifier(const Aws::String& value) { SetSourceDBClusterParameterGroupIdentifier(value); return *this;}

    /**
     * <p>The identifier or Amazon Resource Name (ARN) for the source cluster parameter
     * group.</p> <p>Constraints:</p> <ul> <li> <p>Must specify a valid cluster
     * parameter group.</p> </li> <li> <p>If the source cluster parameter group is in
     * the same Amazon Web Services Region as the copy, specify a valid parameter group
     * identifier; for example, <code>my-db-cluster-param-group</code>, or a valid
     * ARN.</p> </li> <li> <p>If the source parameter group is in a different Amazon
     * Web Services Region than the copy, specify a valid cluster parameter group ARN;
     * for example,
     * <code>arn:aws:rds:us-east-1:123456789012:sample-cluster:sample-parameter-group</code>.</p>
     * </li> </ul>
     */
    inline CopyDBClusterParameterGroupRequest& WithSourceDBClusterParameterGroupIdentifier(Aws::String&& value) { SetSourceDBClusterParameterGroupIdentifier(std::move(value)); return *this;}

    /**
     * <p>The identifier or Amazon Resource Name (ARN) for the source cluster parameter
     * group.</p> <p>Constraints:</p> <ul> <li> <p>Must specify a valid cluster
     * parameter group.</p> </li> <li> <p>If the source cluster parameter group is in
     * the same Amazon Web Services Region as the copy, specify a valid parameter group
     * identifier; for example, <code>my-db-cluster-param-group</code>, or a valid
     * ARN.</p> </li> <li> <p>If the source parameter group is in a different Amazon
     * Web Services Region than the copy, specify a valid cluster parameter group ARN;
     * for example,
     * <code>arn:aws:rds:us-east-1:123456789012:sample-cluster:sample-parameter-group</code>.</p>
     * </li> </ul>
     */
    inline CopyDBClusterParameterGroupRequest& WithSourceDBClusterParameterGroupIdentifier(const char* value) { SetSourceDBClusterParameterGroupIdentifier(value); return *this;}


    /**
     * <p>The identifier for the copied cluster parameter group.</p>
     * <p>Constraints:</p> <ul> <li> <p>Cannot be null, empty, or blank.</p> </li> <li>
     * <p>Must contain from 1 to 255 letters, numbers, or hyphens. </p> </li> <li>
     * <p>The first character must be a letter.</p> </li> <li> <p>Cannot end with a
     * hyphen or contain two consecutive hyphens. </p> </li> </ul> <p>Example:
     * <code>my-cluster-param-group1</code> </p>
     */
    inline const Aws::String& GetTargetDBClusterParameterGroupIdentifier() const{ return m_targetDBClusterParameterGroupIdentifier; }

    /**
     * <p>The identifier for the copied cluster parameter group.</p>
     * <p>Constraints:</p> <ul> <li> <p>Cannot be null, empty, or blank.</p> </li> <li>
     * <p>Must contain from 1 to 255 letters, numbers, or hyphens. </p> </li> <li>
     * <p>The first character must be a letter.</p> </li> <li> <p>Cannot end with a
     * hyphen or contain two consecutive hyphens. </p> </li> </ul> <p>Example:
     * <code>my-cluster-param-group1</code> </p>
     */
    inline bool TargetDBClusterParameterGroupIdentifierHasBeenSet() const { return m_targetDBClusterParameterGroupIdentifierHasBeenSet; }

    /**
     * <p>The identifier for the copied cluster parameter group.</p>
     * <p>Constraints:</p> <ul> <li> <p>Cannot be null, empty, or blank.</p> </li> <li>
     * <p>Must contain from 1 to 255 letters, numbers, or hyphens. </p> </li> <li>
     * <p>The first character must be a letter.</p> </li> <li> <p>Cannot end with a
     * hyphen or contain two consecutive hyphens. </p> </li> </ul> <p>Example:
     * <code>my-cluster-param-group1</code> </p>
     */
    inline void SetTargetDBClusterParameterGroupIdentifier(const Aws::String& value) { m_targetDBClusterParameterGroupIdentifierHasBeenSet = true; m_targetDBClusterParameterGroupIdentifier = value; }

    /**
     * <p>The identifier for the copied cluster parameter group.</p>
     * <p>Constraints:</p> <ul> <li> <p>Cannot be null, empty, or blank.</p> </li> <li>
     * <p>Must contain from 1 to 255 letters, numbers, or hyphens. </p> </li> <li>
     * <p>The first character must be a letter.</p> </li> <li> <p>Cannot end with a
     * hyphen or contain two consecutive hyphens. </p> </li> </ul> <p>Example:
     * <code>my-cluster-param-group1</code> </p>
     */
    inline void SetTargetDBClusterParameterGroupIdentifier(Aws::String&& value) { m_targetDBClusterParameterGroupIdentifierHasBeenSet = true; m_targetDBClusterParameterGroupIdentifier = std::move(value); }

    /**
     * <p>The identifier for the copied cluster parameter group.</p>
     * <p>Constraints:</p> <ul> <li> <p>Cannot be null, empty, or blank.</p> </li> <li>
     * <p>Must contain from 1 to 255 letters, numbers, or hyphens. </p> </li> <li>
     * <p>The first character must be a letter.</p> </li> <li> <p>Cannot end with a
     * hyphen or contain two consecutive hyphens. </p> </li> </ul> <p>Example:
     * <code>my-cluster-param-group1</code> </p>
     */
    inline void SetTargetDBClusterParameterGroupIdentifier(const char* value) { m_targetDBClusterParameterGroupIdentifierHasBeenSet = true; m_targetDBClusterParameterGroupIdentifier.assign(value); }

    /**
     * <p>The identifier for the copied cluster parameter group.</p>
     * <p>Constraints:</p> <ul> <li> <p>Cannot be null, empty, or blank.</p> </li> <li>
     * <p>Must contain from 1 to 255 letters, numbers, or hyphens. </p> </li> <li>
     * <p>The first character must be a letter.</p> </li> <li> <p>Cannot end with a
     * hyphen or contain two consecutive hyphens. </p> </li> </ul> <p>Example:
     * <code>my-cluster-param-group1</code> </p>
     */
    inline CopyDBClusterParameterGroupRequest& WithTargetDBClusterParameterGroupIdentifier(const Aws::String& value) { SetTargetDBClusterParameterGroupIdentifier(value); return *this;}

    /**
     * <p>The identifier for the copied cluster parameter group.</p>
     * <p>Constraints:</p> <ul> <li> <p>Cannot be null, empty, or blank.</p> </li> <li>
     * <p>Must contain from 1 to 255 letters, numbers, or hyphens. </p> </li> <li>
     * <p>The first character must be a letter.</p> </li> <li> <p>Cannot end with a
     * hyphen or contain two consecutive hyphens. </p> </li> </ul> <p>Example:
     * <code>my-cluster-param-group1</code> </p>
     */
    inline CopyDBClusterParameterGroupRequest& WithTargetDBClusterParameterGroupIdentifier(Aws::String&& value) { SetTargetDBClusterParameterGroupIdentifier(std::move(value)); return *this;}

    /**
     * <p>The identifier for the copied cluster parameter group.</p>
     * <p>Constraints:</p> <ul> <li> <p>Cannot be null, empty, or blank.</p> </li> <li>
     * <p>Must contain from 1 to 255 letters, numbers, or hyphens. </p> </li> <li>
     * <p>The first character must be a letter.</p> </li> <li> <p>Cannot end with a
     * hyphen or contain two consecutive hyphens. </p> </li> </ul> <p>Example:
     * <code>my-cluster-param-group1</code> </p>
     */
    inline CopyDBClusterParameterGroupRequest& WithTargetDBClusterParameterGroupIdentifier(const char* value) { SetTargetDBClusterParameterGroupIdentifier(value); return *this;}


    /**
     * <p>A description for the copied cluster parameter group.</p>
     */
    inline const Aws::String& GetTargetDBClusterParameterGroupDescription() const{ return m_targetDBClusterParameterGroupDescription; }

    /**
     * <p>A description for the copied cluster parameter group.</p>
     */
    inline bool TargetDBClusterParameterGroupDescriptionHasBeenSet() const { return m_targetDBClusterParameterGroupDescriptionHasBeenSet; }

    /**
     * <p>A description for the copied cluster parameter group.</p>
     */
    inline void SetTargetDBClusterParameterGroupDescription(const Aws::String& value) { m_targetDBClusterParameterGroupDescriptionHasBeenSet = true; m_targetDBClusterParameterGroupDescription = value; }

    /**
     * <p>A description for the copied cluster parameter group.</p>
     */
    inline void SetTargetDBClusterParameterGroupDescription(Aws::String&& value) { m_targetDBClusterParameterGroupDescriptionHasBeenSet = true; m_targetDBClusterParameterGroupDescription = std::move(value); }

    /**
     * <p>A description for the copied cluster parameter group.</p>
     */
    inline void SetTargetDBClusterParameterGroupDescription(const char* value) { m_targetDBClusterParameterGroupDescriptionHasBeenSet = true; m_targetDBClusterParameterGroupDescription.assign(value); }

    /**
     * <p>A description for the copied cluster parameter group.</p>
     */
    inline CopyDBClusterParameterGroupRequest& WithTargetDBClusterParameterGroupDescription(const Aws::String& value) { SetTargetDBClusterParameterGroupDescription(value); return *this;}

    /**
     * <p>A description for the copied cluster parameter group.</p>
     */
    inline CopyDBClusterParameterGroupRequest& WithTargetDBClusterParameterGroupDescription(Aws::String&& value) { SetTargetDBClusterParameterGroupDescription(std::move(value)); return *this;}

    /**
     * <p>A description for the copied cluster parameter group.</p>
     */
    inline CopyDBClusterParameterGroupRequest& WithTargetDBClusterParameterGroupDescription(const char* value) { SetTargetDBClusterParameterGroupDescription(value); return *this;}


    /**
     * <p>The tags that are to be assigned to the parameter group.</p>
     */
    inline const Aws::Vector<Tag>& GetTags() const{ return m_tags; }

    /**
     * <p>The tags that are to be assigned to the parameter group.</p>
     */
    inline bool TagsHasBeenSet() const { return m_tagsHasBeenSet; }

    /**
     * <p>The tags that are to be assigned to the parameter group.</p>
     */
    inline void SetTags(const Aws::Vector<Tag>& value) { m_tagsHasBeenSet = true; m_tags = value; }

    /**
     * <p>The tags that are to be assigned to the parameter group.</p>
     */
    inline void SetTags(Aws::Vector<Tag>&& value) { m_tagsHasBeenSet = true; m_tags = std::move(value); }

    /**
     * <p>The tags that are to be assigned to the parameter group.</p>
     */
    inline CopyDBClusterParameterGroupRequest& WithTags(const Aws::Vector<Tag>& value) { SetTags(value); return *this;}

    /**
     * <p>The tags that are to be assigned to the parameter group.</p>
     */
    inline CopyDBClusterParameterGroupRequest& WithTags(Aws::Vector<Tag>&& value) { SetTags(std::move(value)); return *this;}

    /**
     * <p>The tags that are to be assigned to the parameter group.</p>
     */
    inline CopyDBClusterParameterGroupRequest& AddTags(const Tag& value) { m_tagsHasBeenSet = true; m_tags.push_back(value); return *this; }

    /**
     * <p>The tags that are to be assigned to the parameter group.</p>
     */
    inline CopyDBClusterParameterGroupRequest& AddTags(Tag&& value) { m_tagsHasBeenSet = true; m_tags.push_back(std::move(value)); return *this; }

  private:

    Aws::String m_sourceDBClusterParameterGroupIdentifier;
    bool m_sourceDBClusterParameterGroupIdentifierHasBeenSet = false;

    Aws::String m_targetDBClusterParameterGroupIdentifier;
    bool m_targetDBClusterParameterGroupIdentifierHasBeenSet = false;

    Aws::String m_targetDBClusterParameterGroupDescription;
    bool m_targetDBClusterParameterGroupDescriptionHasBeenSet = false;

    Aws::Vector<Tag> m_tags;
    bool m_tagsHasBeenSet = false;
  };

} // namespace Model
} // namespace DocDB
} // namespace Aws
