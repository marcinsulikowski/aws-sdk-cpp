﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/swf/SWF_EXPORTS.h>
#include <aws/swf/model/WorkflowType.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/swf/model/TaskList.h>
#include <aws/swf/model/ChildPolicy.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
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
namespace SWF
{
namespace Model
{

  /**
   * <p>Provides the details of the <code>StartChildWorkflowExecution</code>
   * decision.</p> <p> <b>Access Control</b> </p> <p>You can use IAM policies to
   * control this decision's access to Amazon SWF resources as follows:</p> <ul> <li>
   * <p>Use a <code>Resource</code> element with the domain name to limit the action
   * to only specified domains.</p> </li> <li> <p>Use an <code>Action</code> element
   * to allow or deny permission to call this action.</p> </li> <li> <p>Constrain the
   * following parameters by using a <code>Condition</code> element with the
   * appropriate keys.</p> <ul> <li> <p> <code>tagList.member.N</code> – The key is
   * "swf:tagList.N" where N is the tag number from 0 to 4, inclusive.</p> </li> <li>
   * <p> <code>taskList</code> – String constraint. The key is
   * <code>swf:taskList.name</code>.</p> </li> <li> <p>
   * <code>workflowType.name</code> – String constraint. The key is
   * <code>swf:workflowType.name</code>.</p> </li> <li> <p>
   * <code>workflowType.version</code> – String constraint. The key is
   * <code>swf:workflowType.version</code>.</p> </li> </ul> </li> </ul> <p>If the
   * caller doesn't have sufficient permissions to invoke the action, or the
   * parameter values fall outside the specified constraints, the action fails. The
   * associated event attribute's <code>cause</code> parameter is set to
   * <code>OPERATION_NOT_PERMITTED</code>. For details and example IAM policies, see
   * <a
   * href="https://docs.aws.amazon.com/amazonswf/latest/developerguide/swf-dev-iam.html">Using
   * IAM to Manage Access to Amazon SWF Workflows</a> in the <i>Amazon SWF Developer
   * Guide</i>.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/swf-2012-01-25/StartChildWorkflowExecutionDecisionAttributes">AWS
   * API Reference</a></p>
   */
  class AWS_SWF_API StartChildWorkflowExecutionDecisionAttributes
  {
  public:
    StartChildWorkflowExecutionDecisionAttributes();
    StartChildWorkflowExecutionDecisionAttributes(Aws::Utils::Json::JsonView jsonValue);
    StartChildWorkflowExecutionDecisionAttributes& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p> The type of the workflow execution to be started.</p>
     */
    inline const WorkflowType& GetWorkflowType() const{ return m_workflowType; }

    /**
     * <p> The type of the workflow execution to be started.</p>
     */
    inline bool WorkflowTypeHasBeenSet() const { return m_workflowTypeHasBeenSet; }

    /**
     * <p> The type of the workflow execution to be started.</p>
     */
    inline void SetWorkflowType(const WorkflowType& value) { m_workflowTypeHasBeenSet = true; m_workflowType = value; }

    /**
     * <p> The type of the workflow execution to be started.</p>
     */
    inline void SetWorkflowType(WorkflowType&& value) { m_workflowTypeHasBeenSet = true; m_workflowType = std::move(value); }

    /**
     * <p> The type of the workflow execution to be started.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithWorkflowType(const WorkflowType& value) { SetWorkflowType(value); return *this;}

    /**
     * <p> The type of the workflow execution to be started.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithWorkflowType(WorkflowType&& value) { SetWorkflowType(std::move(value)); return *this;}


    /**
     * <p> The <code>workflowId</code> of the workflow execution.</p> <p>The specified
     * string must not start or end with whitespace. It must not contain a
     * <code>:</code> (colon), <code>/</code> (slash), <code>|</code> (vertical bar),
     * or any control characters (<code>\u0000-\u001f</code> |
     * <code>\u007f-\u009f</code>). Also, it must not contain the literal string
     * <code>arn</code>.</p>
     */
    inline const Aws::String& GetWorkflowId() const{ return m_workflowId; }

    /**
     * <p> The <code>workflowId</code> of the workflow execution.</p> <p>The specified
     * string must not start or end with whitespace. It must not contain a
     * <code>:</code> (colon), <code>/</code> (slash), <code>|</code> (vertical bar),
     * or any control characters (<code>\u0000-\u001f</code> |
     * <code>\u007f-\u009f</code>). Also, it must not contain the literal string
     * <code>arn</code>.</p>
     */
    inline bool WorkflowIdHasBeenSet() const { return m_workflowIdHasBeenSet; }

    /**
     * <p> The <code>workflowId</code> of the workflow execution.</p> <p>The specified
     * string must not start or end with whitespace. It must not contain a
     * <code>:</code> (colon), <code>/</code> (slash), <code>|</code> (vertical bar),
     * or any control characters (<code>\u0000-\u001f</code> |
     * <code>\u007f-\u009f</code>). Also, it must not contain the literal string
     * <code>arn</code>.</p>
     */
    inline void SetWorkflowId(const Aws::String& value) { m_workflowIdHasBeenSet = true; m_workflowId = value; }

    /**
     * <p> The <code>workflowId</code> of the workflow execution.</p> <p>The specified
     * string must not start or end with whitespace. It must not contain a
     * <code>:</code> (colon), <code>/</code> (slash), <code>|</code> (vertical bar),
     * or any control characters (<code>\u0000-\u001f</code> |
     * <code>\u007f-\u009f</code>). Also, it must not contain the literal string
     * <code>arn</code>.</p>
     */
    inline void SetWorkflowId(Aws::String&& value) { m_workflowIdHasBeenSet = true; m_workflowId = std::move(value); }

    /**
     * <p> The <code>workflowId</code> of the workflow execution.</p> <p>The specified
     * string must not start or end with whitespace. It must not contain a
     * <code>:</code> (colon), <code>/</code> (slash), <code>|</code> (vertical bar),
     * or any control characters (<code>\u0000-\u001f</code> |
     * <code>\u007f-\u009f</code>). Also, it must not contain the literal string
     * <code>arn</code>.</p>
     */
    inline void SetWorkflowId(const char* value) { m_workflowIdHasBeenSet = true; m_workflowId.assign(value); }

    /**
     * <p> The <code>workflowId</code> of the workflow execution.</p> <p>The specified
     * string must not start or end with whitespace. It must not contain a
     * <code>:</code> (colon), <code>/</code> (slash), <code>|</code> (vertical bar),
     * or any control characters (<code>\u0000-\u001f</code> |
     * <code>\u007f-\u009f</code>). Also, it must not contain the literal string
     * <code>arn</code>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithWorkflowId(const Aws::String& value) { SetWorkflowId(value); return *this;}

    /**
     * <p> The <code>workflowId</code> of the workflow execution.</p> <p>The specified
     * string must not start or end with whitespace. It must not contain a
     * <code>:</code> (colon), <code>/</code> (slash), <code>|</code> (vertical bar),
     * or any control characters (<code>\u0000-\u001f</code> |
     * <code>\u007f-\u009f</code>). Also, it must not contain the literal string
     * <code>arn</code>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithWorkflowId(Aws::String&& value) { SetWorkflowId(std::move(value)); return *this;}

    /**
     * <p> The <code>workflowId</code> of the workflow execution.</p> <p>The specified
     * string must not start or end with whitespace. It must not contain a
     * <code>:</code> (colon), <code>/</code> (slash), <code>|</code> (vertical bar),
     * or any control characters (<code>\u0000-\u001f</code> |
     * <code>\u007f-\u009f</code>). Also, it must not contain the literal string
     * <code>arn</code>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithWorkflowId(const char* value) { SetWorkflowId(value); return *this;}


    /**
     * <p>The data attached to the event that can be used by the decider in subsequent
     * workflow tasks. This data isn't sent to the child workflow execution.</p>
     */
    inline const Aws::String& GetControl() const{ return m_control; }

    /**
     * <p>The data attached to the event that can be used by the decider in subsequent
     * workflow tasks. This data isn't sent to the child workflow execution.</p>
     */
    inline bool ControlHasBeenSet() const { return m_controlHasBeenSet; }

    /**
     * <p>The data attached to the event that can be used by the decider in subsequent
     * workflow tasks. This data isn't sent to the child workflow execution.</p>
     */
    inline void SetControl(const Aws::String& value) { m_controlHasBeenSet = true; m_control = value; }

    /**
     * <p>The data attached to the event that can be used by the decider in subsequent
     * workflow tasks. This data isn't sent to the child workflow execution.</p>
     */
    inline void SetControl(Aws::String&& value) { m_controlHasBeenSet = true; m_control = std::move(value); }

    /**
     * <p>The data attached to the event that can be used by the decider in subsequent
     * workflow tasks. This data isn't sent to the child workflow execution.</p>
     */
    inline void SetControl(const char* value) { m_controlHasBeenSet = true; m_control.assign(value); }

    /**
     * <p>The data attached to the event that can be used by the decider in subsequent
     * workflow tasks. This data isn't sent to the child workflow execution.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithControl(const Aws::String& value) { SetControl(value); return *this;}

    /**
     * <p>The data attached to the event that can be used by the decider in subsequent
     * workflow tasks. This data isn't sent to the child workflow execution.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithControl(Aws::String&& value) { SetControl(std::move(value)); return *this;}

    /**
     * <p>The data attached to the event that can be used by the decider in subsequent
     * workflow tasks. This data isn't sent to the child workflow execution.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithControl(const char* value) { SetControl(value); return *this;}


    /**
     * <p>The input to be provided to the workflow execution.</p>
     */
    inline const Aws::String& GetInput() const{ return m_input; }

    /**
     * <p>The input to be provided to the workflow execution.</p>
     */
    inline bool InputHasBeenSet() const { return m_inputHasBeenSet; }

    /**
     * <p>The input to be provided to the workflow execution.</p>
     */
    inline void SetInput(const Aws::String& value) { m_inputHasBeenSet = true; m_input = value; }

    /**
     * <p>The input to be provided to the workflow execution.</p>
     */
    inline void SetInput(Aws::String&& value) { m_inputHasBeenSet = true; m_input = std::move(value); }

    /**
     * <p>The input to be provided to the workflow execution.</p>
     */
    inline void SetInput(const char* value) { m_inputHasBeenSet = true; m_input.assign(value); }

    /**
     * <p>The input to be provided to the workflow execution.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithInput(const Aws::String& value) { SetInput(value); return *this;}

    /**
     * <p>The input to be provided to the workflow execution.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithInput(Aws::String&& value) { SetInput(std::move(value)); return *this;}

    /**
     * <p>The input to be provided to the workflow execution.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithInput(const char* value) { SetInput(value); return *this;}


    /**
     * <p>The total duration for this workflow execution. This overrides the
     * defaultExecutionStartToCloseTimeout specified when registering the workflow
     * type.</p> <p>The duration is specified in seconds, an integer greater than or
     * equal to <code>0</code>. You can use <code>NONE</code> to specify unlimited
     * duration.</p>  <p>An execution start-to-close timeout for this workflow
     * execution must be specified either as a default for the workflow type or through
     * this parameter. If neither this parameter is set nor a default execution
     * start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline const Aws::String& GetExecutionStartToCloseTimeout() const{ return m_executionStartToCloseTimeout; }

    /**
     * <p>The total duration for this workflow execution. This overrides the
     * defaultExecutionStartToCloseTimeout specified when registering the workflow
     * type.</p> <p>The duration is specified in seconds, an integer greater than or
     * equal to <code>0</code>. You can use <code>NONE</code> to specify unlimited
     * duration.</p>  <p>An execution start-to-close timeout for this workflow
     * execution must be specified either as a default for the workflow type or through
     * this parameter. If neither this parameter is set nor a default execution
     * start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline bool ExecutionStartToCloseTimeoutHasBeenSet() const { return m_executionStartToCloseTimeoutHasBeenSet; }

    /**
     * <p>The total duration for this workflow execution. This overrides the
     * defaultExecutionStartToCloseTimeout specified when registering the workflow
     * type.</p> <p>The duration is specified in seconds, an integer greater than or
     * equal to <code>0</code>. You can use <code>NONE</code> to specify unlimited
     * duration.</p>  <p>An execution start-to-close timeout for this workflow
     * execution must be specified either as a default for the workflow type or through
     * this parameter. If neither this parameter is set nor a default execution
     * start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline void SetExecutionStartToCloseTimeout(const Aws::String& value) { m_executionStartToCloseTimeoutHasBeenSet = true; m_executionStartToCloseTimeout = value; }

    /**
     * <p>The total duration for this workflow execution. This overrides the
     * defaultExecutionStartToCloseTimeout specified when registering the workflow
     * type.</p> <p>The duration is specified in seconds, an integer greater than or
     * equal to <code>0</code>. You can use <code>NONE</code> to specify unlimited
     * duration.</p>  <p>An execution start-to-close timeout for this workflow
     * execution must be specified either as a default for the workflow type or through
     * this parameter. If neither this parameter is set nor a default execution
     * start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline void SetExecutionStartToCloseTimeout(Aws::String&& value) { m_executionStartToCloseTimeoutHasBeenSet = true; m_executionStartToCloseTimeout = std::move(value); }

    /**
     * <p>The total duration for this workflow execution. This overrides the
     * defaultExecutionStartToCloseTimeout specified when registering the workflow
     * type.</p> <p>The duration is specified in seconds, an integer greater than or
     * equal to <code>0</code>. You can use <code>NONE</code> to specify unlimited
     * duration.</p>  <p>An execution start-to-close timeout for this workflow
     * execution must be specified either as a default for the workflow type or through
     * this parameter. If neither this parameter is set nor a default execution
     * start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline void SetExecutionStartToCloseTimeout(const char* value) { m_executionStartToCloseTimeoutHasBeenSet = true; m_executionStartToCloseTimeout.assign(value); }

    /**
     * <p>The total duration for this workflow execution. This overrides the
     * defaultExecutionStartToCloseTimeout specified when registering the workflow
     * type.</p> <p>The duration is specified in seconds, an integer greater than or
     * equal to <code>0</code>. You can use <code>NONE</code> to specify unlimited
     * duration.</p>  <p>An execution start-to-close timeout for this workflow
     * execution must be specified either as a default for the workflow type or through
     * this parameter. If neither this parameter is set nor a default execution
     * start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithExecutionStartToCloseTimeout(const Aws::String& value) { SetExecutionStartToCloseTimeout(value); return *this;}

    /**
     * <p>The total duration for this workflow execution. This overrides the
     * defaultExecutionStartToCloseTimeout specified when registering the workflow
     * type.</p> <p>The duration is specified in seconds, an integer greater than or
     * equal to <code>0</code>. You can use <code>NONE</code> to specify unlimited
     * duration.</p>  <p>An execution start-to-close timeout for this workflow
     * execution must be specified either as a default for the workflow type or through
     * this parameter. If neither this parameter is set nor a default execution
     * start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithExecutionStartToCloseTimeout(Aws::String&& value) { SetExecutionStartToCloseTimeout(std::move(value)); return *this;}

    /**
     * <p>The total duration for this workflow execution. This overrides the
     * defaultExecutionStartToCloseTimeout specified when registering the workflow
     * type.</p> <p>The duration is specified in seconds, an integer greater than or
     * equal to <code>0</code>. You can use <code>NONE</code> to specify unlimited
     * duration.</p>  <p>An execution start-to-close timeout for this workflow
     * execution must be specified either as a default for the workflow type or through
     * this parameter. If neither this parameter is set nor a default execution
     * start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithExecutionStartToCloseTimeout(const char* value) { SetExecutionStartToCloseTimeout(value); return *this;}


    /**
     * <p>The name of the task list to be used for decision tasks of the child workflow
     * execution.</p>  <p>A task list for this workflow execution must be
     * specified either as a default for the workflow type or through this parameter.
     * If neither this parameter is set nor a default task list was specified at
     * registration time then a fault is returned.</p>  <p>The specified string
     * must not start or end with whitespace. It must not contain a <code>:</code>
     * (colon), <code>/</code> (slash), <code>|</code> (vertical bar), or any control
     * characters (<code>\u0000-\u001f</code> | <code>\u007f-\u009f</code>). Also, it
     * must not contain the literal string <code>arn</code>.</p>
     */
    inline const TaskList& GetTaskList() const{ return m_taskList; }

    /**
     * <p>The name of the task list to be used for decision tasks of the child workflow
     * execution.</p>  <p>A task list for this workflow execution must be
     * specified either as a default for the workflow type or through this parameter.
     * If neither this parameter is set nor a default task list was specified at
     * registration time then a fault is returned.</p>  <p>The specified string
     * must not start or end with whitespace. It must not contain a <code>:</code>
     * (colon), <code>/</code> (slash), <code>|</code> (vertical bar), or any control
     * characters (<code>\u0000-\u001f</code> | <code>\u007f-\u009f</code>). Also, it
     * must not contain the literal string <code>arn</code>.</p>
     */
    inline bool TaskListHasBeenSet() const { return m_taskListHasBeenSet; }

    /**
     * <p>The name of the task list to be used for decision tasks of the child workflow
     * execution.</p>  <p>A task list for this workflow execution must be
     * specified either as a default for the workflow type or through this parameter.
     * If neither this parameter is set nor a default task list was specified at
     * registration time then a fault is returned.</p>  <p>The specified string
     * must not start or end with whitespace. It must not contain a <code>:</code>
     * (colon), <code>/</code> (slash), <code>|</code> (vertical bar), or any control
     * characters (<code>\u0000-\u001f</code> | <code>\u007f-\u009f</code>). Also, it
     * must not contain the literal string <code>arn</code>.</p>
     */
    inline void SetTaskList(const TaskList& value) { m_taskListHasBeenSet = true; m_taskList = value; }

    /**
     * <p>The name of the task list to be used for decision tasks of the child workflow
     * execution.</p>  <p>A task list for this workflow execution must be
     * specified either as a default for the workflow type or through this parameter.
     * If neither this parameter is set nor a default task list was specified at
     * registration time then a fault is returned.</p>  <p>The specified string
     * must not start or end with whitespace. It must not contain a <code>:</code>
     * (colon), <code>/</code> (slash), <code>|</code> (vertical bar), or any control
     * characters (<code>\u0000-\u001f</code> | <code>\u007f-\u009f</code>). Also, it
     * must not contain the literal string <code>arn</code>.</p>
     */
    inline void SetTaskList(TaskList&& value) { m_taskListHasBeenSet = true; m_taskList = std::move(value); }

    /**
     * <p>The name of the task list to be used for decision tasks of the child workflow
     * execution.</p>  <p>A task list for this workflow execution must be
     * specified either as a default for the workflow type or through this parameter.
     * If neither this parameter is set nor a default task list was specified at
     * registration time then a fault is returned.</p>  <p>The specified string
     * must not start or end with whitespace. It must not contain a <code>:</code>
     * (colon), <code>/</code> (slash), <code>|</code> (vertical bar), or any control
     * characters (<code>\u0000-\u001f</code> | <code>\u007f-\u009f</code>). Also, it
     * must not contain the literal string <code>arn</code>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithTaskList(const TaskList& value) { SetTaskList(value); return *this;}

    /**
     * <p>The name of the task list to be used for decision tasks of the child workflow
     * execution.</p>  <p>A task list for this workflow execution must be
     * specified either as a default for the workflow type or through this parameter.
     * If neither this parameter is set nor a default task list was specified at
     * registration time then a fault is returned.</p>  <p>The specified string
     * must not start or end with whitespace. It must not contain a <code>:</code>
     * (colon), <code>/</code> (slash), <code>|</code> (vertical bar), or any control
     * characters (<code>\u0000-\u001f</code> | <code>\u007f-\u009f</code>). Also, it
     * must not contain the literal string <code>arn</code>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithTaskList(TaskList&& value) { SetTaskList(std::move(value)); return *this;}


    /**
     * <p> A task priority that, if set, specifies the priority for a decision task of
     * this workflow execution. This overrides the defaultTaskPriority specified when
     * registering the workflow type. Valid values are integers that range from Java's
     * <code>Integer.MIN_VALUE</code> (-2147483648) to <code>Integer.MAX_VALUE</code>
     * (2147483647). Higher numbers indicate higher priority.</p> <p>For more
     * information about setting task priority, see <a
     * href="https://docs.aws.amazon.com/amazonswf/latest/developerguide/programming-priority.html">Setting
     * Task Priority</a> in the <i>Amazon SWF Developer Guide</i>.</p>
     */
    inline const Aws::String& GetTaskPriority() const{ return m_taskPriority; }

    /**
     * <p> A task priority that, if set, specifies the priority for a decision task of
     * this workflow execution. This overrides the defaultTaskPriority specified when
     * registering the workflow type. Valid values are integers that range from Java's
     * <code>Integer.MIN_VALUE</code> (-2147483648) to <code>Integer.MAX_VALUE</code>
     * (2147483647). Higher numbers indicate higher priority.</p> <p>For more
     * information about setting task priority, see <a
     * href="https://docs.aws.amazon.com/amazonswf/latest/developerguide/programming-priority.html">Setting
     * Task Priority</a> in the <i>Amazon SWF Developer Guide</i>.</p>
     */
    inline bool TaskPriorityHasBeenSet() const { return m_taskPriorityHasBeenSet; }

    /**
     * <p> A task priority that, if set, specifies the priority for a decision task of
     * this workflow execution. This overrides the defaultTaskPriority specified when
     * registering the workflow type. Valid values are integers that range from Java's
     * <code>Integer.MIN_VALUE</code> (-2147483648) to <code>Integer.MAX_VALUE</code>
     * (2147483647). Higher numbers indicate higher priority.</p> <p>For more
     * information about setting task priority, see <a
     * href="https://docs.aws.amazon.com/amazonswf/latest/developerguide/programming-priority.html">Setting
     * Task Priority</a> in the <i>Amazon SWF Developer Guide</i>.</p>
     */
    inline void SetTaskPriority(const Aws::String& value) { m_taskPriorityHasBeenSet = true; m_taskPriority = value; }

    /**
     * <p> A task priority that, if set, specifies the priority for a decision task of
     * this workflow execution. This overrides the defaultTaskPriority specified when
     * registering the workflow type. Valid values are integers that range from Java's
     * <code>Integer.MIN_VALUE</code> (-2147483648) to <code>Integer.MAX_VALUE</code>
     * (2147483647). Higher numbers indicate higher priority.</p> <p>For more
     * information about setting task priority, see <a
     * href="https://docs.aws.amazon.com/amazonswf/latest/developerguide/programming-priority.html">Setting
     * Task Priority</a> in the <i>Amazon SWF Developer Guide</i>.</p>
     */
    inline void SetTaskPriority(Aws::String&& value) { m_taskPriorityHasBeenSet = true; m_taskPriority = std::move(value); }

    /**
     * <p> A task priority that, if set, specifies the priority for a decision task of
     * this workflow execution. This overrides the defaultTaskPriority specified when
     * registering the workflow type. Valid values are integers that range from Java's
     * <code>Integer.MIN_VALUE</code> (-2147483648) to <code>Integer.MAX_VALUE</code>
     * (2147483647). Higher numbers indicate higher priority.</p> <p>For more
     * information about setting task priority, see <a
     * href="https://docs.aws.amazon.com/amazonswf/latest/developerguide/programming-priority.html">Setting
     * Task Priority</a> in the <i>Amazon SWF Developer Guide</i>.</p>
     */
    inline void SetTaskPriority(const char* value) { m_taskPriorityHasBeenSet = true; m_taskPriority.assign(value); }

    /**
     * <p> A task priority that, if set, specifies the priority for a decision task of
     * this workflow execution. This overrides the defaultTaskPriority specified when
     * registering the workflow type. Valid values are integers that range from Java's
     * <code>Integer.MIN_VALUE</code> (-2147483648) to <code>Integer.MAX_VALUE</code>
     * (2147483647). Higher numbers indicate higher priority.</p> <p>For more
     * information about setting task priority, see <a
     * href="https://docs.aws.amazon.com/amazonswf/latest/developerguide/programming-priority.html">Setting
     * Task Priority</a> in the <i>Amazon SWF Developer Guide</i>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithTaskPriority(const Aws::String& value) { SetTaskPriority(value); return *this;}

    /**
     * <p> A task priority that, if set, specifies the priority for a decision task of
     * this workflow execution. This overrides the defaultTaskPriority specified when
     * registering the workflow type. Valid values are integers that range from Java's
     * <code>Integer.MIN_VALUE</code> (-2147483648) to <code>Integer.MAX_VALUE</code>
     * (2147483647). Higher numbers indicate higher priority.</p> <p>For more
     * information about setting task priority, see <a
     * href="https://docs.aws.amazon.com/amazonswf/latest/developerguide/programming-priority.html">Setting
     * Task Priority</a> in the <i>Amazon SWF Developer Guide</i>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithTaskPriority(Aws::String&& value) { SetTaskPriority(std::move(value)); return *this;}

    /**
     * <p> A task priority that, if set, specifies the priority for a decision task of
     * this workflow execution. This overrides the defaultTaskPriority specified when
     * registering the workflow type. Valid values are integers that range from Java's
     * <code>Integer.MIN_VALUE</code> (-2147483648) to <code>Integer.MAX_VALUE</code>
     * (2147483647). Higher numbers indicate higher priority.</p> <p>For more
     * information about setting task priority, see <a
     * href="https://docs.aws.amazon.com/amazonswf/latest/developerguide/programming-priority.html">Setting
     * Task Priority</a> in the <i>Amazon SWF Developer Guide</i>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithTaskPriority(const char* value) { SetTaskPriority(value); return *this;}


    /**
     * <p>Specifies the maximum duration of decision tasks for this workflow execution.
     * This parameter overrides the <code>defaultTaskStartToCloseTimout</code>
     * specified when registering the workflow type using
     * <a>RegisterWorkflowType</a>.</p> <p>The duration is specified in seconds, an
     * integer greater than or equal to <code>0</code>. You can use <code>NONE</code>
     * to specify unlimited duration.</p>  <p>A task start-to-close timeout for
     * this workflow execution must be specified either as a default for the workflow
     * type or through this parameter. If neither this parameter is set nor a default
     * task start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline const Aws::String& GetTaskStartToCloseTimeout() const{ return m_taskStartToCloseTimeout; }

    /**
     * <p>Specifies the maximum duration of decision tasks for this workflow execution.
     * This parameter overrides the <code>defaultTaskStartToCloseTimout</code>
     * specified when registering the workflow type using
     * <a>RegisterWorkflowType</a>.</p> <p>The duration is specified in seconds, an
     * integer greater than or equal to <code>0</code>. You can use <code>NONE</code>
     * to specify unlimited duration.</p>  <p>A task start-to-close timeout for
     * this workflow execution must be specified either as a default for the workflow
     * type or through this parameter. If neither this parameter is set nor a default
     * task start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline bool TaskStartToCloseTimeoutHasBeenSet() const { return m_taskStartToCloseTimeoutHasBeenSet; }

    /**
     * <p>Specifies the maximum duration of decision tasks for this workflow execution.
     * This parameter overrides the <code>defaultTaskStartToCloseTimout</code>
     * specified when registering the workflow type using
     * <a>RegisterWorkflowType</a>.</p> <p>The duration is specified in seconds, an
     * integer greater than or equal to <code>0</code>. You can use <code>NONE</code>
     * to specify unlimited duration.</p>  <p>A task start-to-close timeout for
     * this workflow execution must be specified either as a default for the workflow
     * type or through this parameter. If neither this parameter is set nor a default
     * task start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline void SetTaskStartToCloseTimeout(const Aws::String& value) { m_taskStartToCloseTimeoutHasBeenSet = true; m_taskStartToCloseTimeout = value; }

    /**
     * <p>Specifies the maximum duration of decision tasks for this workflow execution.
     * This parameter overrides the <code>defaultTaskStartToCloseTimout</code>
     * specified when registering the workflow type using
     * <a>RegisterWorkflowType</a>.</p> <p>The duration is specified in seconds, an
     * integer greater than or equal to <code>0</code>. You can use <code>NONE</code>
     * to specify unlimited duration.</p>  <p>A task start-to-close timeout for
     * this workflow execution must be specified either as a default for the workflow
     * type or through this parameter. If neither this parameter is set nor a default
     * task start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline void SetTaskStartToCloseTimeout(Aws::String&& value) { m_taskStartToCloseTimeoutHasBeenSet = true; m_taskStartToCloseTimeout = std::move(value); }

    /**
     * <p>Specifies the maximum duration of decision tasks for this workflow execution.
     * This parameter overrides the <code>defaultTaskStartToCloseTimout</code>
     * specified when registering the workflow type using
     * <a>RegisterWorkflowType</a>.</p> <p>The duration is specified in seconds, an
     * integer greater than or equal to <code>0</code>. You can use <code>NONE</code>
     * to specify unlimited duration.</p>  <p>A task start-to-close timeout for
     * this workflow execution must be specified either as a default for the workflow
     * type or through this parameter. If neither this parameter is set nor a default
     * task start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline void SetTaskStartToCloseTimeout(const char* value) { m_taskStartToCloseTimeoutHasBeenSet = true; m_taskStartToCloseTimeout.assign(value); }

    /**
     * <p>Specifies the maximum duration of decision tasks for this workflow execution.
     * This parameter overrides the <code>defaultTaskStartToCloseTimout</code>
     * specified when registering the workflow type using
     * <a>RegisterWorkflowType</a>.</p> <p>The duration is specified in seconds, an
     * integer greater than or equal to <code>0</code>. You can use <code>NONE</code>
     * to specify unlimited duration.</p>  <p>A task start-to-close timeout for
     * this workflow execution must be specified either as a default for the workflow
     * type or through this parameter. If neither this parameter is set nor a default
     * task start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithTaskStartToCloseTimeout(const Aws::String& value) { SetTaskStartToCloseTimeout(value); return *this;}

    /**
     * <p>Specifies the maximum duration of decision tasks for this workflow execution.
     * This parameter overrides the <code>defaultTaskStartToCloseTimout</code>
     * specified when registering the workflow type using
     * <a>RegisterWorkflowType</a>.</p> <p>The duration is specified in seconds, an
     * integer greater than or equal to <code>0</code>. You can use <code>NONE</code>
     * to specify unlimited duration.</p>  <p>A task start-to-close timeout for
     * this workflow execution must be specified either as a default for the workflow
     * type or through this parameter. If neither this parameter is set nor a default
     * task start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithTaskStartToCloseTimeout(Aws::String&& value) { SetTaskStartToCloseTimeout(std::move(value)); return *this;}

    /**
     * <p>Specifies the maximum duration of decision tasks for this workflow execution.
     * This parameter overrides the <code>defaultTaskStartToCloseTimout</code>
     * specified when registering the workflow type using
     * <a>RegisterWorkflowType</a>.</p> <p>The duration is specified in seconds, an
     * integer greater than or equal to <code>0</code>. You can use <code>NONE</code>
     * to specify unlimited duration.</p>  <p>A task start-to-close timeout for
     * this workflow execution must be specified either as a default for the workflow
     * type or through this parameter. If neither this parameter is set nor a default
     * task start-to-close timeout was specified at registration time then a fault is
     * returned.</p> 
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithTaskStartToCloseTimeout(const char* value) { SetTaskStartToCloseTimeout(value); return *this;}


    /**
     * <p> If set, specifies the policy to use for the child workflow executions if the
     * workflow execution being started is terminated by calling the
     * <a>TerminateWorkflowExecution</a> action explicitly or due to an expired
     * timeout. This policy overrides the default child policy specified when
     * registering the workflow type using <a>RegisterWorkflowType</a>.</p> <p>The
     * supported child policies are:</p> <ul> <li> <p> <code>TERMINATE</code> – The
     * child executions are terminated.</p> </li> <li> <p> <code>REQUEST_CANCEL</code>
     * – A request to cancel is attempted for each child execution by recording a
     * <code>WorkflowExecutionCancelRequested</code> event in its history. It is up to
     * the decider to take appropriate actions when it receives an execution history
     * with this event.</p> </li> <li> <p> <code>ABANDON</code> – No action is taken.
     * The child executions continue to run.</p> </li> </ul>  <p>A child policy
     * for this workflow execution must be specified either as a default for the
     * workflow type or through this parameter. If neither this parameter is set nor a
     * default child policy was specified at registration time then a fault is
     * returned.</p> 
     */
    inline const ChildPolicy& GetChildPolicy() const{ return m_childPolicy; }

    /**
     * <p> If set, specifies the policy to use for the child workflow executions if the
     * workflow execution being started is terminated by calling the
     * <a>TerminateWorkflowExecution</a> action explicitly or due to an expired
     * timeout. This policy overrides the default child policy specified when
     * registering the workflow type using <a>RegisterWorkflowType</a>.</p> <p>The
     * supported child policies are:</p> <ul> <li> <p> <code>TERMINATE</code> – The
     * child executions are terminated.</p> </li> <li> <p> <code>REQUEST_CANCEL</code>
     * – A request to cancel is attempted for each child execution by recording a
     * <code>WorkflowExecutionCancelRequested</code> event in its history. It is up to
     * the decider to take appropriate actions when it receives an execution history
     * with this event.</p> </li> <li> <p> <code>ABANDON</code> – No action is taken.
     * The child executions continue to run.</p> </li> </ul>  <p>A child policy
     * for this workflow execution must be specified either as a default for the
     * workflow type or through this parameter. If neither this parameter is set nor a
     * default child policy was specified at registration time then a fault is
     * returned.</p> 
     */
    inline bool ChildPolicyHasBeenSet() const { return m_childPolicyHasBeenSet; }

    /**
     * <p> If set, specifies the policy to use for the child workflow executions if the
     * workflow execution being started is terminated by calling the
     * <a>TerminateWorkflowExecution</a> action explicitly or due to an expired
     * timeout. This policy overrides the default child policy specified when
     * registering the workflow type using <a>RegisterWorkflowType</a>.</p> <p>The
     * supported child policies are:</p> <ul> <li> <p> <code>TERMINATE</code> – The
     * child executions are terminated.</p> </li> <li> <p> <code>REQUEST_CANCEL</code>
     * – A request to cancel is attempted for each child execution by recording a
     * <code>WorkflowExecutionCancelRequested</code> event in its history. It is up to
     * the decider to take appropriate actions when it receives an execution history
     * with this event.</p> </li> <li> <p> <code>ABANDON</code> – No action is taken.
     * The child executions continue to run.</p> </li> </ul>  <p>A child policy
     * for this workflow execution must be specified either as a default for the
     * workflow type or through this parameter. If neither this parameter is set nor a
     * default child policy was specified at registration time then a fault is
     * returned.</p> 
     */
    inline void SetChildPolicy(const ChildPolicy& value) { m_childPolicyHasBeenSet = true; m_childPolicy = value; }

    /**
     * <p> If set, specifies the policy to use for the child workflow executions if the
     * workflow execution being started is terminated by calling the
     * <a>TerminateWorkflowExecution</a> action explicitly or due to an expired
     * timeout. This policy overrides the default child policy specified when
     * registering the workflow type using <a>RegisterWorkflowType</a>.</p> <p>The
     * supported child policies are:</p> <ul> <li> <p> <code>TERMINATE</code> – The
     * child executions are terminated.</p> </li> <li> <p> <code>REQUEST_CANCEL</code>
     * – A request to cancel is attempted for each child execution by recording a
     * <code>WorkflowExecutionCancelRequested</code> event in its history. It is up to
     * the decider to take appropriate actions when it receives an execution history
     * with this event.</p> </li> <li> <p> <code>ABANDON</code> – No action is taken.
     * The child executions continue to run.</p> </li> </ul>  <p>A child policy
     * for this workflow execution must be specified either as a default for the
     * workflow type or through this parameter. If neither this parameter is set nor a
     * default child policy was specified at registration time then a fault is
     * returned.</p> 
     */
    inline void SetChildPolicy(ChildPolicy&& value) { m_childPolicyHasBeenSet = true; m_childPolicy = std::move(value); }

    /**
     * <p> If set, specifies the policy to use for the child workflow executions if the
     * workflow execution being started is terminated by calling the
     * <a>TerminateWorkflowExecution</a> action explicitly or due to an expired
     * timeout. This policy overrides the default child policy specified when
     * registering the workflow type using <a>RegisterWorkflowType</a>.</p> <p>The
     * supported child policies are:</p> <ul> <li> <p> <code>TERMINATE</code> – The
     * child executions are terminated.</p> </li> <li> <p> <code>REQUEST_CANCEL</code>
     * – A request to cancel is attempted for each child execution by recording a
     * <code>WorkflowExecutionCancelRequested</code> event in its history. It is up to
     * the decider to take appropriate actions when it receives an execution history
     * with this event.</p> </li> <li> <p> <code>ABANDON</code> – No action is taken.
     * The child executions continue to run.</p> </li> </ul>  <p>A child policy
     * for this workflow execution must be specified either as a default for the
     * workflow type or through this parameter. If neither this parameter is set nor a
     * default child policy was specified at registration time then a fault is
     * returned.</p> 
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithChildPolicy(const ChildPolicy& value) { SetChildPolicy(value); return *this;}

    /**
     * <p> If set, specifies the policy to use for the child workflow executions if the
     * workflow execution being started is terminated by calling the
     * <a>TerminateWorkflowExecution</a> action explicitly or due to an expired
     * timeout. This policy overrides the default child policy specified when
     * registering the workflow type using <a>RegisterWorkflowType</a>.</p> <p>The
     * supported child policies are:</p> <ul> <li> <p> <code>TERMINATE</code> – The
     * child executions are terminated.</p> </li> <li> <p> <code>REQUEST_CANCEL</code>
     * – A request to cancel is attempted for each child execution by recording a
     * <code>WorkflowExecutionCancelRequested</code> event in its history. It is up to
     * the decider to take appropriate actions when it receives an execution history
     * with this event.</p> </li> <li> <p> <code>ABANDON</code> – No action is taken.
     * The child executions continue to run.</p> </li> </ul>  <p>A child policy
     * for this workflow execution must be specified either as a default for the
     * workflow type or through this parameter. If neither this parameter is set nor a
     * default child policy was specified at registration time then a fault is
     * returned.</p> 
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithChildPolicy(ChildPolicy&& value) { SetChildPolicy(std::move(value)); return *this;}


    /**
     * <p>The list of tags to associate with the child workflow execution. A maximum of
     * 5 tags can be specified. You can list workflow executions with a specific tag by
     * calling <a>ListOpenWorkflowExecutions</a> or <a>ListClosedWorkflowExecutions</a>
     * and specifying a <a>TagFilter</a>.</p>
     */
    inline const Aws::Vector<Aws::String>& GetTagList() const{ return m_tagList; }

    /**
     * <p>The list of tags to associate with the child workflow execution. A maximum of
     * 5 tags can be specified. You can list workflow executions with a specific tag by
     * calling <a>ListOpenWorkflowExecutions</a> or <a>ListClosedWorkflowExecutions</a>
     * and specifying a <a>TagFilter</a>.</p>
     */
    inline bool TagListHasBeenSet() const { return m_tagListHasBeenSet; }

    /**
     * <p>The list of tags to associate with the child workflow execution. A maximum of
     * 5 tags can be specified. You can list workflow executions with a specific tag by
     * calling <a>ListOpenWorkflowExecutions</a> or <a>ListClosedWorkflowExecutions</a>
     * and specifying a <a>TagFilter</a>.</p>
     */
    inline void SetTagList(const Aws::Vector<Aws::String>& value) { m_tagListHasBeenSet = true; m_tagList = value; }

    /**
     * <p>The list of tags to associate with the child workflow execution. A maximum of
     * 5 tags can be specified. You can list workflow executions with a specific tag by
     * calling <a>ListOpenWorkflowExecutions</a> or <a>ListClosedWorkflowExecutions</a>
     * and specifying a <a>TagFilter</a>.</p>
     */
    inline void SetTagList(Aws::Vector<Aws::String>&& value) { m_tagListHasBeenSet = true; m_tagList = std::move(value); }

    /**
     * <p>The list of tags to associate with the child workflow execution. A maximum of
     * 5 tags can be specified. You can list workflow executions with a specific tag by
     * calling <a>ListOpenWorkflowExecutions</a> or <a>ListClosedWorkflowExecutions</a>
     * and specifying a <a>TagFilter</a>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithTagList(const Aws::Vector<Aws::String>& value) { SetTagList(value); return *this;}

    /**
     * <p>The list of tags to associate with the child workflow execution. A maximum of
     * 5 tags can be specified. You can list workflow executions with a specific tag by
     * calling <a>ListOpenWorkflowExecutions</a> or <a>ListClosedWorkflowExecutions</a>
     * and specifying a <a>TagFilter</a>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithTagList(Aws::Vector<Aws::String>&& value) { SetTagList(std::move(value)); return *this;}

    /**
     * <p>The list of tags to associate with the child workflow execution. A maximum of
     * 5 tags can be specified. You can list workflow executions with a specific tag by
     * calling <a>ListOpenWorkflowExecutions</a> or <a>ListClosedWorkflowExecutions</a>
     * and specifying a <a>TagFilter</a>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& AddTagList(const Aws::String& value) { m_tagListHasBeenSet = true; m_tagList.push_back(value); return *this; }

    /**
     * <p>The list of tags to associate with the child workflow execution. A maximum of
     * 5 tags can be specified. You can list workflow executions with a specific tag by
     * calling <a>ListOpenWorkflowExecutions</a> or <a>ListClosedWorkflowExecutions</a>
     * and specifying a <a>TagFilter</a>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& AddTagList(Aws::String&& value) { m_tagListHasBeenSet = true; m_tagList.push_back(std::move(value)); return *this; }

    /**
     * <p>The list of tags to associate with the child workflow execution. A maximum of
     * 5 tags can be specified. You can list workflow executions with a specific tag by
     * calling <a>ListOpenWorkflowExecutions</a> or <a>ListClosedWorkflowExecutions</a>
     * and specifying a <a>TagFilter</a>.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& AddTagList(const char* value) { m_tagListHasBeenSet = true; m_tagList.push_back(value); return *this; }


    /**
     * <p>The IAM role attached to the child workflow execution.</p>
     */
    inline const Aws::String& GetLambdaRole() const{ return m_lambdaRole; }

    /**
     * <p>The IAM role attached to the child workflow execution.</p>
     */
    inline bool LambdaRoleHasBeenSet() const { return m_lambdaRoleHasBeenSet; }

    /**
     * <p>The IAM role attached to the child workflow execution.</p>
     */
    inline void SetLambdaRole(const Aws::String& value) { m_lambdaRoleHasBeenSet = true; m_lambdaRole = value; }

    /**
     * <p>The IAM role attached to the child workflow execution.</p>
     */
    inline void SetLambdaRole(Aws::String&& value) { m_lambdaRoleHasBeenSet = true; m_lambdaRole = std::move(value); }

    /**
     * <p>The IAM role attached to the child workflow execution.</p>
     */
    inline void SetLambdaRole(const char* value) { m_lambdaRoleHasBeenSet = true; m_lambdaRole.assign(value); }

    /**
     * <p>The IAM role attached to the child workflow execution.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithLambdaRole(const Aws::String& value) { SetLambdaRole(value); return *this;}

    /**
     * <p>The IAM role attached to the child workflow execution.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithLambdaRole(Aws::String&& value) { SetLambdaRole(std::move(value)); return *this;}

    /**
     * <p>The IAM role attached to the child workflow execution.</p>
     */
    inline StartChildWorkflowExecutionDecisionAttributes& WithLambdaRole(const char* value) { SetLambdaRole(value); return *this;}

  private:

    WorkflowType m_workflowType;
    bool m_workflowTypeHasBeenSet = false;

    Aws::String m_workflowId;
    bool m_workflowIdHasBeenSet = false;

    Aws::String m_control;
    bool m_controlHasBeenSet = false;

    Aws::String m_input;
    bool m_inputHasBeenSet = false;

    Aws::String m_executionStartToCloseTimeout;
    bool m_executionStartToCloseTimeoutHasBeenSet = false;

    TaskList m_taskList;
    bool m_taskListHasBeenSet = false;

    Aws::String m_taskPriority;
    bool m_taskPriorityHasBeenSet = false;

    Aws::String m_taskStartToCloseTimeout;
    bool m_taskStartToCloseTimeoutHasBeenSet = false;

    ChildPolicy m_childPolicy;
    bool m_childPolicyHasBeenSet = false;

    Aws::Vector<Aws::String> m_tagList;
    bool m_tagListHasBeenSet = false;

    Aws::String m_lambdaRole;
    bool m_lambdaRoleHasBeenSet = false;
  };

} // namespace Model
} // namespace SWF
} // namespace Aws
