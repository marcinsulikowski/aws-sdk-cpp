﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/sagemaker/SageMaker_EXPORTS.h>
#include <aws/sagemaker/SageMakerRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/sagemaker/model/NotebookInstanceSortKey.h>
#include <aws/sagemaker/model/NotebookInstanceSortOrder.h>
#include <aws/core/utils/DateTime.h>
#include <aws/sagemaker/model/NotebookInstanceStatus.h>
#include <utility>

namespace Aws
{
namespace SageMaker
{
namespace Model
{

  /**
   */
  class AWS_SAGEMAKER_API ListNotebookInstancesRequest : public SageMakerRequest
  {
  public:
    ListNotebookInstancesRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "ListNotebookInstances"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p> If the previous call to the <code>ListNotebookInstances</code> is truncated,
     * the response includes a <code>NextToken</code>. You can use this token in your
     * subsequent <code>ListNotebookInstances</code> request to fetch the next set of
     * notebook instances. </p>  <p>You might specify a filter or a sort order in
     * your request. When response is truncated, you must use the same values for the
     * filer and sort order in the next request. </p> 
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p> If the previous call to the <code>ListNotebookInstances</code> is truncated,
     * the response includes a <code>NextToken</code>. You can use this token in your
     * subsequent <code>ListNotebookInstances</code> request to fetch the next set of
     * notebook instances. </p>  <p>You might specify a filter or a sort order in
     * your request. When response is truncated, you must use the same values for the
     * filer and sort order in the next request. </p> 
     */
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }

    /**
     * <p> If the previous call to the <code>ListNotebookInstances</code> is truncated,
     * the response includes a <code>NextToken</code>. You can use this token in your
     * subsequent <code>ListNotebookInstances</code> request to fetch the next set of
     * notebook instances. </p>  <p>You might specify a filter or a sort order in
     * your request. When response is truncated, you must use the same values for the
     * filer and sort order in the next request. </p> 
     */
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    /**
     * <p> If the previous call to the <code>ListNotebookInstances</code> is truncated,
     * the response includes a <code>NextToken</code>. You can use this token in your
     * subsequent <code>ListNotebookInstances</code> request to fetch the next set of
     * notebook instances. </p>  <p>You might specify a filter or a sort order in
     * your request. When response is truncated, you must use the same values for the
     * filer and sort order in the next request. </p> 
     */
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }

    /**
     * <p> If the previous call to the <code>ListNotebookInstances</code> is truncated,
     * the response includes a <code>NextToken</code>. You can use this token in your
     * subsequent <code>ListNotebookInstances</code> request to fetch the next set of
     * notebook instances. </p>  <p>You might specify a filter or a sort order in
     * your request. When response is truncated, you must use the same values for the
     * filer and sort order in the next request. </p> 
     */
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    /**
     * <p> If the previous call to the <code>ListNotebookInstances</code> is truncated,
     * the response includes a <code>NextToken</code>. You can use this token in your
     * subsequent <code>ListNotebookInstances</code> request to fetch the next set of
     * notebook instances. </p>  <p>You might specify a filter or a sort order in
     * your request. When response is truncated, you must use the same values for the
     * filer and sort order in the next request. </p> 
     */
    inline ListNotebookInstancesRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p> If the previous call to the <code>ListNotebookInstances</code> is truncated,
     * the response includes a <code>NextToken</code>. You can use this token in your
     * subsequent <code>ListNotebookInstances</code> request to fetch the next set of
     * notebook instances. </p>  <p>You might specify a filter or a sort order in
     * your request. When response is truncated, you must use the same values for the
     * filer and sort order in the next request. </p> 
     */
    inline ListNotebookInstancesRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p> If the previous call to the <code>ListNotebookInstances</code> is truncated,
     * the response includes a <code>NextToken</code>. You can use this token in your
     * subsequent <code>ListNotebookInstances</code> request to fetch the next set of
     * notebook instances. </p>  <p>You might specify a filter or a sort order in
     * your request. When response is truncated, you must use the same values for the
     * filer and sort order in the next request. </p> 
     */
    inline ListNotebookInstancesRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}


    /**
     * <p>The maximum number of notebook instances to return.</p>
     */
    inline int GetMaxResults() const{ return m_maxResults; }

    /**
     * <p>The maximum number of notebook instances to return.</p>
     */
    inline bool MaxResultsHasBeenSet() const { return m_maxResultsHasBeenSet; }

    /**
     * <p>The maximum number of notebook instances to return.</p>
     */
    inline void SetMaxResults(int value) { m_maxResultsHasBeenSet = true; m_maxResults = value; }

    /**
     * <p>The maximum number of notebook instances to return.</p>
     */
    inline ListNotebookInstancesRequest& WithMaxResults(int value) { SetMaxResults(value); return *this;}


    /**
     * <p>The field to sort results by. The default is <code>Name</code>.</p>
     */
    inline const NotebookInstanceSortKey& GetSortBy() const{ return m_sortBy; }

    /**
     * <p>The field to sort results by. The default is <code>Name</code>.</p>
     */
    inline bool SortByHasBeenSet() const { return m_sortByHasBeenSet; }

    /**
     * <p>The field to sort results by. The default is <code>Name</code>.</p>
     */
    inline void SetSortBy(const NotebookInstanceSortKey& value) { m_sortByHasBeenSet = true; m_sortBy = value; }

    /**
     * <p>The field to sort results by. The default is <code>Name</code>.</p>
     */
    inline void SetSortBy(NotebookInstanceSortKey&& value) { m_sortByHasBeenSet = true; m_sortBy = std::move(value); }

    /**
     * <p>The field to sort results by. The default is <code>Name</code>.</p>
     */
    inline ListNotebookInstancesRequest& WithSortBy(const NotebookInstanceSortKey& value) { SetSortBy(value); return *this;}

    /**
     * <p>The field to sort results by. The default is <code>Name</code>.</p>
     */
    inline ListNotebookInstancesRequest& WithSortBy(NotebookInstanceSortKey&& value) { SetSortBy(std::move(value)); return *this;}


    /**
     * <p>The sort order for results. </p>
     */
    inline const NotebookInstanceSortOrder& GetSortOrder() const{ return m_sortOrder; }

    /**
     * <p>The sort order for results. </p>
     */
    inline bool SortOrderHasBeenSet() const { return m_sortOrderHasBeenSet; }

    /**
     * <p>The sort order for results. </p>
     */
    inline void SetSortOrder(const NotebookInstanceSortOrder& value) { m_sortOrderHasBeenSet = true; m_sortOrder = value; }

    /**
     * <p>The sort order for results. </p>
     */
    inline void SetSortOrder(NotebookInstanceSortOrder&& value) { m_sortOrderHasBeenSet = true; m_sortOrder = std::move(value); }

    /**
     * <p>The sort order for results. </p>
     */
    inline ListNotebookInstancesRequest& WithSortOrder(const NotebookInstanceSortOrder& value) { SetSortOrder(value); return *this;}

    /**
     * <p>The sort order for results. </p>
     */
    inline ListNotebookInstancesRequest& WithSortOrder(NotebookInstanceSortOrder&& value) { SetSortOrder(std::move(value)); return *this;}


    /**
     * <p>A string in the notebook instances' name. This filter returns only notebook
     * instances whose name contains the specified string.</p>
     */
    inline const Aws::String& GetNameContains() const{ return m_nameContains; }

    /**
     * <p>A string in the notebook instances' name. This filter returns only notebook
     * instances whose name contains the specified string.</p>
     */
    inline bool NameContainsHasBeenSet() const { return m_nameContainsHasBeenSet; }

    /**
     * <p>A string in the notebook instances' name. This filter returns only notebook
     * instances whose name contains the specified string.</p>
     */
    inline void SetNameContains(const Aws::String& value) { m_nameContainsHasBeenSet = true; m_nameContains = value; }

    /**
     * <p>A string in the notebook instances' name. This filter returns only notebook
     * instances whose name contains the specified string.</p>
     */
    inline void SetNameContains(Aws::String&& value) { m_nameContainsHasBeenSet = true; m_nameContains = std::move(value); }

    /**
     * <p>A string in the notebook instances' name. This filter returns only notebook
     * instances whose name contains the specified string.</p>
     */
    inline void SetNameContains(const char* value) { m_nameContainsHasBeenSet = true; m_nameContains.assign(value); }

    /**
     * <p>A string in the notebook instances' name. This filter returns only notebook
     * instances whose name contains the specified string.</p>
     */
    inline ListNotebookInstancesRequest& WithNameContains(const Aws::String& value) { SetNameContains(value); return *this;}

    /**
     * <p>A string in the notebook instances' name. This filter returns only notebook
     * instances whose name contains the specified string.</p>
     */
    inline ListNotebookInstancesRequest& WithNameContains(Aws::String&& value) { SetNameContains(std::move(value)); return *this;}

    /**
     * <p>A string in the notebook instances' name. This filter returns only notebook
     * instances whose name contains the specified string.</p>
     */
    inline ListNotebookInstancesRequest& WithNameContains(const char* value) { SetNameContains(value); return *this;}


    /**
     * <p>A filter that returns only notebook instances that were created before the
     * specified time (timestamp). </p>
     */
    inline const Aws::Utils::DateTime& GetCreationTimeBefore() const{ return m_creationTimeBefore; }

    /**
     * <p>A filter that returns only notebook instances that were created before the
     * specified time (timestamp). </p>
     */
    inline bool CreationTimeBeforeHasBeenSet() const { return m_creationTimeBeforeHasBeenSet; }

    /**
     * <p>A filter that returns only notebook instances that were created before the
     * specified time (timestamp). </p>
     */
    inline void SetCreationTimeBefore(const Aws::Utils::DateTime& value) { m_creationTimeBeforeHasBeenSet = true; m_creationTimeBefore = value; }

    /**
     * <p>A filter that returns only notebook instances that were created before the
     * specified time (timestamp). </p>
     */
    inline void SetCreationTimeBefore(Aws::Utils::DateTime&& value) { m_creationTimeBeforeHasBeenSet = true; m_creationTimeBefore = std::move(value); }

    /**
     * <p>A filter that returns only notebook instances that were created before the
     * specified time (timestamp). </p>
     */
    inline ListNotebookInstancesRequest& WithCreationTimeBefore(const Aws::Utils::DateTime& value) { SetCreationTimeBefore(value); return *this;}

    /**
     * <p>A filter that returns only notebook instances that were created before the
     * specified time (timestamp). </p>
     */
    inline ListNotebookInstancesRequest& WithCreationTimeBefore(Aws::Utils::DateTime&& value) { SetCreationTimeBefore(std::move(value)); return *this;}


    /**
     * <p>A filter that returns only notebook instances that were created after the
     * specified time (timestamp).</p>
     */
    inline const Aws::Utils::DateTime& GetCreationTimeAfter() const{ return m_creationTimeAfter; }

    /**
     * <p>A filter that returns only notebook instances that were created after the
     * specified time (timestamp).</p>
     */
    inline bool CreationTimeAfterHasBeenSet() const { return m_creationTimeAfterHasBeenSet; }

    /**
     * <p>A filter that returns only notebook instances that were created after the
     * specified time (timestamp).</p>
     */
    inline void SetCreationTimeAfter(const Aws::Utils::DateTime& value) { m_creationTimeAfterHasBeenSet = true; m_creationTimeAfter = value; }

    /**
     * <p>A filter that returns only notebook instances that were created after the
     * specified time (timestamp).</p>
     */
    inline void SetCreationTimeAfter(Aws::Utils::DateTime&& value) { m_creationTimeAfterHasBeenSet = true; m_creationTimeAfter = std::move(value); }

    /**
     * <p>A filter that returns only notebook instances that were created after the
     * specified time (timestamp).</p>
     */
    inline ListNotebookInstancesRequest& WithCreationTimeAfter(const Aws::Utils::DateTime& value) { SetCreationTimeAfter(value); return *this;}

    /**
     * <p>A filter that returns only notebook instances that were created after the
     * specified time (timestamp).</p>
     */
    inline ListNotebookInstancesRequest& WithCreationTimeAfter(Aws::Utils::DateTime&& value) { SetCreationTimeAfter(std::move(value)); return *this;}


    /**
     * <p>A filter that returns only notebook instances that were modified before the
     * specified time (timestamp).</p>
     */
    inline const Aws::Utils::DateTime& GetLastModifiedTimeBefore() const{ return m_lastModifiedTimeBefore; }

    /**
     * <p>A filter that returns only notebook instances that were modified before the
     * specified time (timestamp).</p>
     */
    inline bool LastModifiedTimeBeforeHasBeenSet() const { return m_lastModifiedTimeBeforeHasBeenSet; }

    /**
     * <p>A filter that returns only notebook instances that were modified before the
     * specified time (timestamp).</p>
     */
    inline void SetLastModifiedTimeBefore(const Aws::Utils::DateTime& value) { m_lastModifiedTimeBeforeHasBeenSet = true; m_lastModifiedTimeBefore = value; }

    /**
     * <p>A filter that returns only notebook instances that were modified before the
     * specified time (timestamp).</p>
     */
    inline void SetLastModifiedTimeBefore(Aws::Utils::DateTime&& value) { m_lastModifiedTimeBeforeHasBeenSet = true; m_lastModifiedTimeBefore = std::move(value); }

    /**
     * <p>A filter that returns only notebook instances that were modified before the
     * specified time (timestamp).</p>
     */
    inline ListNotebookInstancesRequest& WithLastModifiedTimeBefore(const Aws::Utils::DateTime& value) { SetLastModifiedTimeBefore(value); return *this;}

    /**
     * <p>A filter that returns only notebook instances that were modified before the
     * specified time (timestamp).</p>
     */
    inline ListNotebookInstancesRequest& WithLastModifiedTimeBefore(Aws::Utils::DateTime&& value) { SetLastModifiedTimeBefore(std::move(value)); return *this;}


    /**
     * <p>A filter that returns only notebook instances that were modified after the
     * specified time (timestamp).</p>
     */
    inline const Aws::Utils::DateTime& GetLastModifiedTimeAfter() const{ return m_lastModifiedTimeAfter; }

    /**
     * <p>A filter that returns only notebook instances that were modified after the
     * specified time (timestamp).</p>
     */
    inline bool LastModifiedTimeAfterHasBeenSet() const { return m_lastModifiedTimeAfterHasBeenSet; }

    /**
     * <p>A filter that returns only notebook instances that were modified after the
     * specified time (timestamp).</p>
     */
    inline void SetLastModifiedTimeAfter(const Aws::Utils::DateTime& value) { m_lastModifiedTimeAfterHasBeenSet = true; m_lastModifiedTimeAfter = value; }

    /**
     * <p>A filter that returns only notebook instances that were modified after the
     * specified time (timestamp).</p>
     */
    inline void SetLastModifiedTimeAfter(Aws::Utils::DateTime&& value) { m_lastModifiedTimeAfterHasBeenSet = true; m_lastModifiedTimeAfter = std::move(value); }

    /**
     * <p>A filter that returns only notebook instances that were modified after the
     * specified time (timestamp).</p>
     */
    inline ListNotebookInstancesRequest& WithLastModifiedTimeAfter(const Aws::Utils::DateTime& value) { SetLastModifiedTimeAfter(value); return *this;}

    /**
     * <p>A filter that returns only notebook instances that were modified after the
     * specified time (timestamp).</p>
     */
    inline ListNotebookInstancesRequest& WithLastModifiedTimeAfter(Aws::Utils::DateTime&& value) { SetLastModifiedTimeAfter(std::move(value)); return *this;}


    /**
     * <p>A filter that returns only notebook instances with the specified status.</p>
     */
    inline const NotebookInstanceStatus& GetStatusEquals() const{ return m_statusEquals; }

    /**
     * <p>A filter that returns only notebook instances with the specified status.</p>
     */
    inline bool StatusEqualsHasBeenSet() const { return m_statusEqualsHasBeenSet; }

    /**
     * <p>A filter that returns only notebook instances with the specified status.</p>
     */
    inline void SetStatusEquals(const NotebookInstanceStatus& value) { m_statusEqualsHasBeenSet = true; m_statusEquals = value; }

    /**
     * <p>A filter that returns only notebook instances with the specified status.</p>
     */
    inline void SetStatusEquals(NotebookInstanceStatus&& value) { m_statusEqualsHasBeenSet = true; m_statusEquals = std::move(value); }

    /**
     * <p>A filter that returns only notebook instances with the specified status.</p>
     */
    inline ListNotebookInstancesRequest& WithStatusEquals(const NotebookInstanceStatus& value) { SetStatusEquals(value); return *this;}

    /**
     * <p>A filter that returns only notebook instances with the specified status.</p>
     */
    inline ListNotebookInstancesRequest& WithStatusEquals(NotebookInstanceStatus&& value) { SetStatusEquals(std::move(value)); return *this;}


    /**
     * <p>A string in the name of a notebook instances lifecycle configuration
     * associated with this notebook instance. This filter returns only notebook
     * instances associated with a lifecycle configuration with a name that contains
     * the specified string.</p>
     */
    inline const Aws::String& GetNotebookInstanceLifecycleConfigNameContains() const{ return m_notebookInstanceLifecycleConfigNameContains; }

    /**
     * <p>A string in the name of a notebook instances lifecycle configuration
     * associated with this notebook instance. This filter returns only notebook
     * instances associated with a lifecycle configuration with a name that contains
     * the specified string.</p>
     */
    inline bool NotebookInstanceLifecycleConfigNameContainsHasBeenSet() const { return m_notebookInstanceLifecycleConfigNameContainsHasBeenSet; }

    /**
     * <p>A string in the name of a notebook instances lifecycle configuration
     * associated with this notebook instance. This filter returns only notebook
     * instances associated with a lifecycle configuration with a name that contains
     * the specified string.</p>
     */
    inline void SetNotebookInstanceLifecycleConfigNameContains(const Aws::String& value) { m_notebookInstanceLifecycleConfigNameContainsHasBeenSet = true; m_notebookInstanceLifecycleConfigNameContains = value; }

    /**
     * <p>A string in the name of a notebook instances lifecycle configuration
     * associated with this notebook instance. This filter returns only notebook
     * instances associated with a lifecycle configuration with a name that contains
     * the specified string.</p>
     */
    inline void SetNotebookInstanceLifecycleConfigNameContains(Aws::String&& value) { m_notebookInstanceLifecycleConfigNameContainsHasBeenSet = true; m_notebookInstanceLifecycleConfigNameContains = std::move(value); }

    /**
     * <p>A string in the name of a notebook instances lifecycle configuration
     * associated with this notebook instance. This filter returns only notebook
     * instances associated with a lifecycle configuration with a name that contains
     * the specified string.</p>
     */
    inline void SetNotebookInstanceLifecycleConfigNameContains(const char* value) { m_notebookInstanceLifecycleConfigNameContainsHasBeenSet = true; m_notebookInstanceLifecycleConfigNameContains.assign(value); }

    /**
     * <p>A string in the name of a notebook instances lifecycle configuration
     * associated with this notebook instance. This filter returns only notebook
     * instances associated with a lifecycle configuration with a name that contains
     * the specified string.</p>
     */
    inline ListNotebookInstancesRequest& WithNotebookInstanceLifecycleConfigNameContains(const Aws::String& value) { SetNotebookInstanceLifecycleConfigNameContains(value); return *this;}

    /**
     * <p>A string in the name of a notebook instances lifecycle configuration
     * associated with this notebook instance. This filter returns only notebook
     * instances associated with a lifecycle configuration with a name that contains
     * the specified string.</p>
     */
    inline ListNotebookInstancesRequest& WithNotebookInstanceLifecycleConfigNameContains(Aws::String&& value) { SetNotebookInstanceLifecycleConfigNameContains(std::move(value)); return *this;}

    /**
     * <p>A string in the name of a notebook instances lifecycle configuration
     * associated with this notebook instance. This filter returns only notebook
     * instances associated with a lifecycle configuration with a name that contains
     * the specified string.</p>
     */
    inline ListNotebookInstancesRequest& WithNotebookInstanceLifecycleConfigNameContains(const char* value) { SetNotebookInstanceLifecycleConfigNameContains(value); return *this;}


    /**
     * <p>A string in the name or URL of a Git repository associated with this notebook
     * instance. This filter returns only notebook instances associated with a git
     * repository with a name that contains the specified string.</p>
     */
    inline const Aws::String& GetDefaultCodeRepositoryContains() const{ return m_defaultCodeRepositoryContains; }

    /**
     * <p>A string in the name or URL of a Git repository associated with this notebook
     * instance. This filter returns only notebook instances associated with a git
     * repository with a name that contains the specified string.</p>
     */
    inline bool DefaultCodeRepositoryContainsHasBeenSet() const { return m_defaultCodeRepositoryContainsHasBeenSet; }

    /**
     * <p>A string in the name or URL of a Git repository associated with this notebook
     * instance. This filter returns only notebook instances associated with a git
     * repository with a name that contains the specified string.</p>
     */
    inline void SetDefaultCodeRepositoryContains(const Aws::String& value) { m_defaultCodeRepositoryContainsHasBeenSet = true; m_defaultCodeRepositoryContains = value; }

    /**
     * <p>A string in the name or URL of a Git repository associated with this notebook
     * instance. This filter returns only notebook instances associated with a git
     * repository with a name that contains the specified string.</p>
     */
    inline void SetDefaultCodeRepositoryContains(Aws::String&& value) { m_defaultCodeRepositoryContainsHasBeenSet = true; m_defaultCodeRepositoryContains = std::move(value); }

    /**
     * <p>A string in the name or URL of a Git repository associated with this notebook
     * instance. This filter returns only notebook instances associated with a git
     * repository with a name that contains the specified string.</p>
     */
    inline void SetDefaultCodeRepositoryContains(const char* value) { m_defaultCodeRepositoryContainsHasBeenSet = true; m_defaultCodeRepositoryContains.assign(value); }

    /**
     * <p>A string in the name or URL of a Git repository associated with this notebook
     * instance. This filter returns only notebook instances associated with a git
     * repository with a name that contains the specified string.</p>
     */
    inline ListNotebookInstancesRequest& WithDefaultCodeRepositoryContains(const Aws::String& value) { SetDefaultCodeRepositoryContains(value); return *this;}

    /**
     * <p>A string in the name or URL of a Git repository associated with this notebook
     * instance. This filter returns only notebook instances associated with a git
     * repository with a name that contains the specified string.</p>
     */
    inline ListNotebookInstancesRequest& WithDefaultCodeRepositoryContains(Aws::String&& value) { SetDefaultCodeRepositoryContains(std::move(value)); return *this;}

    /**
     * <p>A string in the name or URL of a Git repository associated with this notebook
     * instance. This filter returns only notebook instances associated with a git
     * repository with a name that contains the specified string.</p>
     */
    inline ListNotebookInstancesRequest& WithDefaultCodeRepositoryContains(const char* value) { SetDefaultCodeRepositoryContains(value); return *this;}


    /**
     * <p>A filter that returns only notebook instances with associated with the
     * specified git repository.</p>
     */
    inline const Aws::String& GetAdditionalCodeRepositoryEquals() const{ return m_additionalCodeRepositoryEquals; }

    /**
     * <p>A filter that returns only notebook instances with associated with the
     * specified git repository.</p>
     */
    inline bool AdditionalCodeRepositoryEqualsHasBeenSet() const { return m_additionalCodeRepositoryEqualsHasBeenSet; }

    /**
     * <p>A filter that returns only notebook instances with associated with the
     * specified git repository.</p>
     */
    inline void SetAdditionalCodeRepositoryEquals(const Aws::String& value) { m_additionalCodeRepositoryEqualsHasBeenSet = true; m_additionalCodeRepositoryEquals = value; }

    /**
     * <p>A filter that returns only notebook instances with associated with the
     * specified git repository.</p>
     */
    inline void SetAdditionalCodeRepositoryEquals(Aws::String&& value) { m_additionalCodeRepositoryEqualsHasBeenSet = true; m_additionalCodeRepositoryEquals = std::move(value); }

    /**
     * <p>A filter that returns only notebook instances with associated with the
     * specified git repository.</p>
     */
    inline void SetAdditionalCodeRepositoryEquals(const char* value) { m_additionalCodeRepositoryEqualsHasBeenSet = true; m_additionalCodeRepositoryEquals.assign(value); }

    /**
     * <p>A filter that returns only notebook instances with associated with the
     * specified git repository.</p>
     */
    inline ListNotebookInstancesRequest& WithAdditionalCodeRepositoryEquals(const Aws::String& value) { SetAdditionalCodeRepositoryEquals(value); return *this;}

    /**
     * <p>A filter that returns only notebook instances with associated with the
     * specified git repository.</p>
     */
    inline ListNotebookInstancesRequest& WithAdditionalCodeRepositoryEquals(Aws::String&& value) { SetAdditionalCodeRepositoryEquals(std::move(value)); return *this;}

    /**
     * <p>A filter that returns only notebook instances with associated with the
     * specified git repository.</p>
     */
    inline ListNotebookInstancesRequest& WithAdditionalCodeRepositoryEquals(const char* value) { SetAdditionalCodeRepositoryEquals(value); return *this;}

  private:

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;

    int m_maxResults;
    bool m_maxResultsHasBeenSet = false;

    NotebookInstanceSortKey m_sortBy;
    bool m_sortByHasBeenSet = false;

    NotebookInstanceSortOrder m_sortOrder;
    bool m_sortOrderHasBeenSet = false;

    Aws::String m_nameContains;
    bool m_nameContainsHasBeenSet = false;

    Aws::Utils::DateTime m_creationTimeBefore;
    bool m_creationTimeBeforeHasBeenSet = false;

    Aws::Utils::DateTime m_creationTimeAfter;
    bool m_creationTimeAfterHasBeenSet = false;

    Aws::Utils::DateTime m_lastModifiedTimeBefore;
    bool m_lastModifiedTimeBeforeHasBeenSet = false;

    Aws::Utils::DateTime m_lastModifiedTimeAfter;
    bool m_lastModifiedTimeAfterHasBeenSet = false;

    NotebookInstanceStatus m_statusEquals;
    bool m_statusEqualsHasBeenSet = false;

    Aws::String m_notebookInstanceLifecycleConfigNameContains;
    bool m_notebookInstanceLifecycleConfigNameContainsHasBeenSet = false;

    Aws::String m_defaultCodeRepositoryContains;
    bool m_defaultCodeRepositoryContainsHasBeenSet = false;

    Aws::String m_additionalCodeRepositoryEquals;
    bool m_additionalCodeRepositoryEqualsHasBeenSet = false;
  };

} // namespace Model
} // namespace SageMaker
} // namespace Aws
