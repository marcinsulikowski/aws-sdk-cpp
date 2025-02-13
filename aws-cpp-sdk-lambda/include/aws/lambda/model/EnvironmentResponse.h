﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/lambda/Lambda_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSMap.h>
#include <aws/lambda/model/EnvironmentError.h>
#include <aws/core/utils/memory/stl/AWSString.h>
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
namespace Lambda
{
namespace Model
{

  /**
   * <p>The results of an operation to update or read environment variables. If the
   * operation is successful, the response contains the environment variables. If it
   * failed, the response contains details about the error.</p><p><h3>See Also:</h3> 
   * <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/lambda-2015-03-31/EnvironmentResponse">AWS
   * API Reference</a></p>
   */
  class AWS_LAMBDA_API EnvironmentResponse
  {
  public:
    EnvironmentResponse();
    EnvironmentResponse(Aws::Utils::Json::JsonView jsonValue);
    EnvironmentResponse& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline const Aws::Map<Aws::String, Aws::String>& GetVariables() const{ return m_variables; }

    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline bool VariablesHasBeenSet() const { return m_variablesHasBeenSet; }

    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline void SetVariables(const Aws::Map<Aws::String, Aws::String>& value) { m_variablesHasBeenSet = true; m_variables = value; }

    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline void SetVariables(Aws::Map<Aws::String, Aws::String>&& value) { m_variablesHasBeenSet = true; m_variables = std::move(value); }

    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline EnvironmentResponse& WithVariables(const Aws::Map<Aws::String, Aws::String>& value) { SetVariables(value); return *this;}

    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline EnvironmentResponse& WithVariables(Aws::Map<Aws::String, Aws::String>&& value) { SetVariables(std::move(value)); return *this;}

    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline EnvironmentResponse& AddVariables(const Aws::String& key, const Aws::String& value) { m_variablesHasBeenSet = true; m_variables.emplace(key, value); return *this; }

    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline EnvironmentResponse& AddVariables(Aws::String&& key, const Aws::String& value) { m_variablesHasBeenSet = true; m_variables.emplace(std::move(key), value); return *this; }

    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline EnvironmentResponse& AddVariables(const Aws::String& key, Aws::String&& value) { m_variablesHasBeenSet = true; m_variables.emplace(key, std::move(value)); return *this; }

    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline EnvironmentResponse& AddVariables(Aws::String&& key, Aws::String&& value) { m_variablesHasBeenSet = true; m_variables.emplace(std::move(key), std::move(value)); return *this; }

    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline EnvironmentResponse& AddVariables(const char* key, Aws::String&& value) { m_variablesHasBeenSet = true; m_variables.emplace(key, std::move(value)); return *this; }

    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline EnvironmentResponse& AddVariables(Aws::String&& key, const char* value) { m_variablesHasBeenSet = true; m_variables.emplace(std::move(key), value); return *this; }

    /**
     * <p>Environment variable key-value pairs.</p>
     */
    inline EnvironmentResponse& AddVariables(const char* key, const char* value) { m_variablesHasBeenSet = true; m_variables.emplace(key, value); return *this; }


    /**
     * <p>Error messages for environment variables that couldn't be applied.</p>
     */
    inline const EnvironmentError& GetError() const{ return m_error; }

    /**
     * <p>Error messages for environment variables that couldn't be applied.</p>
     */
    inline bool ErrorHasBeenSet() const { return m_errorHasBeenSet; }

    /**
     * <p>Error messages for environment variables that couldn't be applied.</p>
     */
    inline void SetError(const EnvironmentError& value) { m_errorHasBeenSet = true; m_error = value; }

    /**
     * <p>Error messages for environment variables that couldn't be applied.</p>
     */
    inline void SetError(EnvironmentError&& value) { m_errorHasBeenSet = true; m_error = std::move(value); }

    /**
     * <p>Error messages for environment variables that couldn't be applied.</p>
     */
    inline EnvironmentResponse& WithError(const EnvironmentError& value) { SetError(value); return *this;}

    /**
     * <p>Error messages for environment variables that couldn't be applied.</p>
     */
    inline EnvironmentResponse& WithError(EnvironmentError&& value) { SetError(std::move(value)); return *this;}

  private:

    Aws::Map<Aws::String, Aws::String> m_variables;
    bool m_variablesHasBeenSet = false;

    EnvironmentError m_error;
    bool m_errorHasBeenSet = false;
  };

} // namespace Model
} // namespace Lambda
} // namespace Aws
