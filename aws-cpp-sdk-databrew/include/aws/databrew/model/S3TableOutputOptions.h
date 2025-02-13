﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/databrew/GlueDataBrew_EXPORTS.h>
#include <aws/databrew/model/S3Location.h>
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
namespace GlueDataBrew
{
namespace Model
{

  /**
   * <p>Represents options that specify how and where DataBrew writes the Amazon S3
   * output generated by recipe jobs.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/databrew-2017-07-25/S3TableOutputOptions">AWS
   * API Reference</a></p>
   */
  class AWS_GLUEDATABREW_API S3TableOutputOptions
  {
  public:
    S3TableOutputOptions();
    S3TableOutputOptions(Aws::Utils::Json::JsonView jsonValue);
    S3TableOutputOptions& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>Represents an Amazon S3 location (bucket name and object key) where DataBrew
     * can write output from a job.</p>
     */
    inline const S3Location& GetLocation() const{ return m_location; }

    /**
     * <p>Represents an Amazon S3 location (bucket name and object key) where DataBrew
     * can write output from a job.</p>
     */
    inline bool LocationHasBeenSet() const { return m_locationHasBeenSet; }

    /**
     * <p>Represents an Amazon S3 location (bucket name and object key) where DataBrew
     * can write output from a job.</p>
     */
    inline void SetLocation(const S3Location& value) { m_locationHasBeenSet = true; m_location = value; }

    /**
     * <p>Represents an Amazon S3 location (bucket name and object key) where DataBrew
     * can write output from a job.</p>
     */
    inline void SetLocation(S3Location&& value) { m_locationHasBeenSet = true; m_location = std::move(value); }

    /**
     * <p>Represents an Amazon S3 location (bucket name and object key) where DataBrew
     * can write output from a job.</p>
     */
    inline S3TableOutputOptions& WithLocation(const S3Location& value) { SetLocation(value); return *this;}

    /**
     * <p>Represents an Amazon S3 location (bucket name and object key) where DataBrew
     * can write output from a job.</p>
     */
    inline S3TableOutputOptions& WithLocation(S3Location&& value) { SetLocation(std::move(value)); return *this;}

  private:

    S3Location m_location;
    bool m_locationHasBeenSet = false;
  };

} // namespace Model
} // namespace GlueDataBrew
} // namespace Aws
