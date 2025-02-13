﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/appmesh/AppMesh_EXPORTS.h>
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
namespace AppMesh
{
namespace Model
{

  /**
   * <p>An object that represents a Transport Layer Security (TLS) Secret Discovery
   * Service validation context trust. The proxy must be configured with a local SDS
   * provider via a Unix Domain Socket. See App Mesh <a
   * href="https://docs.aws.amazon.com/app-mesh/latest/userguide/tls.html">TLS
   * documentation</a> for more info.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/appmesh-2019-01-25/TlsValidationContextSdsTrust">AWS
   * API Reference</a></p>
   */
  class AWS_APPMESH_API TlsValidationContextSdsTrust
  {
  public:
    TlsValidationContextSdsTrust();
    TlsValidationContextSdsTrust(Aws::Utils::Json::JsonView jsonValue);
    TlsValidationContextSdsTrust& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>A reference to an object that represents the name of the secret for a
     * Transport Layer Security (TLS) Secret Discovery Service validation context
     * trust.</p>
     */
    inline const Aws::String& GetSecretName() const{ return m_secretName; }

    /**
     * <p>A reference to an object that represents the name of the secret for a
     * Transport Layer Security (TLS) Secret Discovery Service validation context
     * trust.</p>
     */
    inline bool SecretNameHasBeenSet() const { return m_secretNameHasBeenSet; }

    /**
     * <p>A reference to an object that represents the name of the secret for a
     * Transport Layer Security (TLS) Secret Discovery Service validation context
     * trust.</p>
     */
    inline void SetSecretName(const Aws::String& value) { m_secretNameHasBeenSet = true; m_secretName = value; }

    /**
     * <p>A reference to an object that represents the name of the secret for a
     * Transport Layer Security (TLS) Secret Discovery Service validation context
     * trust.</p>
     */
    inline void SetSecretName(Aws::String&& value) { m_secretNameHasBeenSet = true; m_secretName = std::move(value); }

    /**
     * <p>A reference to an object that represents the name of the secret for a
     * Transport Layer Security (TLS) Secret Discovery Service validation context
     * trust.</p>
     */
    inline void SetSecretName(const char* value) { m_secretNameHasBeenSet = true; m_secretName.assign(value); }

    /**
     * <p>A reference to an object that represents the name of the secret for a
     * Transport Layer Security (TLS) Secret Discovery Service validation context
     * trust.</p>
     */
    inline TlsValidationContextSdsTrust& WithSecretName(const Aws::String& value) { SetSecretName(value); return *this;}

    /**
     * <p>A reference to an object that represents the name of the secret for a
     * Transport Layer Security (TLS) Secret Discovery Service validation context
     * trust.</p>
     */
    inline TlsValidationContextSdsTrust& WithSecretName(Aws::String&& value) { SetSecretName(std::move(value)); return *this;}

    /**
     * <p>A reference to an object that represents the name of the secret for a
     * Transport Layer Security (TLS) Secret Discovery Service validation context
     * trust.</p>
     */
    inline TlsValidationContextSdsTrust& WithSecretName(const char* value) { SetSecretName(value); return *this;}

  private:

    Aws::String m_secretName;
    bool m_secretNameHasBeenSet = false;
  };

} // namespace Model
} // namespace AppMesh
} // namespace Aws
