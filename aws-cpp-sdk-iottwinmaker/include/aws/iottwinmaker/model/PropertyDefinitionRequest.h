﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/iottwinmaker/IoTTwinMaker_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSMap.h>
#include <aws/iottwinmaker/model/DataType.h>
#include <aws/iottwinmaker/model/DataValue.h>
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
namespace IoTTwinMaker
{
namespace Model
{

  /**
   * <p>An object that sets information about a property.</p><p><h3>See Also:</h3>  
   * <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/iottwinmaker-2021-11-29/PropertyDefinitionRequest">AWS
   * API Reference</a></p>
   */
  class AWS_IOTTWINMAKER_API PropertyDefinitionRequest
  {
  public:
    PropertyDefinitionRequest();
    PropertyDefinitionRequest(Aws::Utils::Json::JsonView jsonValue);
    PropertyDefinitionRequest& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline const Aws::Map<Aws::String, Aws::String>& GetConfiguration() const{ return m_configuration; }

    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline bool ConfigurationHasBeenSet() const { return m_configurationHasBeenSet; }

    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline void SetConfiguration(const Aws::Map<Aws::String, Aws::String>& value) { m_configurationHasBeenSet = true; m_configuration = value; }

    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline void SetConfiguration(Aws::Map<Aws::String, Aws::String>&& value) { m_configurationHasBeenSet = true; m_configuration = std::move(value); }

    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline PropertyDefinitionRequest& WithConfiguration(const Aws::Map<Aws::String, Aws::String>& value) { SetConfiguration(value); return *this;}

    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline PropertyDefinitionRequest& WithConfiguration(Aws::Map<Aws::String, Aws::String>&& value) { SetConfiguration(std::move(value)); return *this;}

    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline PropertyDefinitionRequest& AddConfiguration(const Aws::String& key, const Aws::String& value) { m_configurationHasBeenSet = true; m_configuration.emplace(key, value); return *this; }

    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline PropertyDefinitionRequest& AddConfiguration(Aws::String&& key, const Aws::String& value) { m_configurationHasBeenSet = true; m_configuration.emplace(std::move(key), value); return *this; }

    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline PropertyDefinitionRequest& AddConfiguration(const Aws::String& key, Aws::String&& value) { m_configurationHasBeenSet = true; m_configuration.emplace(key, std::move(value)); return *this; }

    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline PropertyDefinitionRequest& AddConfiguration(Aws::String&& key, Aws::String&& value) { m_configurationHasBeenSet = true; m_configuration.emplace(std::move(key), std::move(value)); return *this; }

    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline PropertyDefinitionRequest& AddConfiguration(const char* key, Aws::String&& value) { m_configurationHasBeenSet = true; m_configuration.emplace(key, std::move(value)); return *this; }

    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline PropertyDefinitionRequest& AddConfiguration(Aws::String&& key, const char* value) { m_configurationHasBeenSet = true; m_configuration.emplace(std::move(key), value); return *this; }

    /**
     * <p>A mapping that specifies configuration information about the property. Use
     * this field to specify information that you read from and write to an external
     * source.</p>
     */
    inline PropertyDefinitionRequest& AddConfiguration(const char* key, const char* value) { m_configurationHasBeenSet = true; m_configuration.emplace(key, value); return *this; }


    /**
     * <p>An object that contains information about the data type.</p>
     */
    inline const DataType& GetDataType() const{ return m_dataType; }

    /**
     * <p>An object that contains information about the data type.</p>
     */
    inline bool DataTypeHasBeenSet() const { return m_dataTypeHasBeenSet; }

    /**
     * <p>An object that contains information about the data type.</p>
     */
    inline void SetDataType(const DataType& value) { m_dataTypeHasBeenSet = true; m_dataType = value; }

    /**
     * <p>An object that contains information about the data type.</p>
     */
    inline void SetDataType(DataType&& value) { m_dataTypeHasBeenSet = true; m_dataType = std::move(value); }

    /**
     * <p>An object that contains information about the data type.</p>
     */
    inline PropertyDefinitionRequest& WithDataType(const DataType& value) { SetDataType(value); return *this;}

    /**
     * <p>An object that contains information about the data type.</p>
     */
    inline PropertyDefinitionRequest& WithDataType(DataType&& value) { SetDataType(std::move(value)); return *this;}


    /**
     * <p>An object that contains the default value.</p>
     */
    inline const DataValue& GetDefaultValue() const{ return m_defaultValue; }

    /**
     * <p>An object that contains the default value.</p>
     */
    inline bool DefaultValueHasBeenSet() const { return m_defaultValueHasBeenSet; }

    /**
     * <p>An object that contains the default value.</p>
     */
    inline void SetDefaultValue(const DataValue& value) { m_defaultValueHasBeenSet = true; m_defaultValue = value; }

    /**
     * <p>An object that contains the default value.</p>
     */
    inline void SetDefaultValue(DataValue&& value) { m_defaultValueHasBeenSet = true; m_defaultValue = std::move(value); }

    /**
     * <p>An object that contains the default value.</p>
     */
    inline PropertyDefinitionRequest& WithDefaultValue(const DataValue& value) { SetDefaultValue(value); return *this;}

    /**
     * <p>An object that contains the default value.</p>
     */
    inline PropertyDefinitionRequest& WithDefaultValue(DataValue&& value) { SetDefaultValue(std::move(value)); return *this;}


    /**
     * <p>A Boolean value that specifies whether the property ID comes from an external
     * data store.</p>
     */
    inline bool GetIsExternalId() const{ return m_isExternalId; }

    /**
     * <p>A Boolean value that specifies whether the property ID comes from an external
     * data store.</p>
     */
    inline bool IsExternalIdHasBeenSet() const { return m_isExternalIdHasBeenSet; }

    /**
     * <p>A Boolean value that specifies whether the property ID comes from an external
     * data store.</p>
     */
    inline void SetIsExternalId(bool value) { m_isExternalIdHasBeenSet = true; m_isExternalId = value; }

    /**
     * <p>A Boolean value that specifies whether the property ID comes from an external
     * data store.</p>
     */
    inline PropertyDefinitionRequest& WithIsExternalId(bool value) { SetIsExternalId(value); return *this;}


    /**
     * <p>A Boolean value that specifies whether the property is required.</p>
     */
    inline bool GetIsRequiredInEntity() const{ return m_isRequiredInEntity; }

    /**
     * <p>A Boolean value that specifies whether the property is required.</p>
     */
    inline bool IsRequiredInEntityHasBeenSet() const { return m_isRequiredInEntityHasBeenSet; }

    /**
     * <p>A Boolean value that specifies whether the property is required.</p>
     */
    inline void SetIsRequiredInEntity(bool value) { m_isRequiredInEntityHasBeenSet = true; m_isRequiredInEntity = value; }

    /**
     * <p>A Boolean value that specifies whether the property is required.</p>
     */
    inline PropertyDefinitionRequest& WithIsRequiredInEntity(bool value) { SetIsRequiredInEntity(value); return *this;}


    /**
     * <p>A Boolean value that specifies whether the property is stored externally.</p>
     */
    inline bool GetIsStoredExternally() const{ return m_isStoredExternally; }

    /**
     * <p>A Boolean value that specifies whether the property is stored externally.</p>
     */
    inline bool IsStoredExternallyHasBeenSet() const { return m_isStoredExternallyHasBeenSet; }

    /**
     * <p>A Boolean value that specifies whether the property is stored externally.</p>
     */
    inline void SetIsStoredExternally(bool value) { m_isStoredExternallyHasBeenSet = true; m_isStoredExternally = value; }

    /**
     * <p>A Boolean value that specifies whether the property is stored externally.</p>
     */
    inline PropertyDefinitionRequest& WithIsStoredExternally(bool value) { SetIsStoredExternally(value); return *this;}


    /**
     * <p>A Boolean value that specifies whether the property consists of time series
     * data.</p>
     */
    inline bool GetIsTimeSeries() const{ return m_isTimeSeries; }

    /**
     * <p>A Boolean value that specifies whether the property consists of time series
     * data.</p>
     */
    inline bool IsTimeSeriesHasBeenSet() const { return m_isTimeSeriesHasBeenSet; }

    /**
     * <p>A Boolean value that specifies whether the property consists of time series
     * data.</p>
     */
    inline void SetIsTimeSeries(bool value) { m_isTimeSeriesHasBeenSet = true; m_isTimeSeries = value; }

    /**
     * <p>A Boolean value that specifies whether the property consists of time series
     * data.</p>
     */
    inline PropertyDefinitionRequest& WithIsTimeSeries(bool value) { SetIsTimeSeries(value); return *this;}

  private:

    Aws::Map<Aws::String, Aws::String> m_configuration;
    bool m_configurationHasBeenSet = false;

    DataType m_dataType;
    bool m_dataTypeHasBeenSet = false;

    DataValue m_defaultValue;
    bool m_defaultValueHasBeenSet = false;

    bool m_isExternalId;
    bool m_isExternalIdHasBeenSet = false;

    bool m_isRequiredInEntity;
    bool m_isRequiredInEntityHasBeenSet = false;

    bool m_isStoredExternally;
    bool m_isStoredExternallyHasBeenSet = false;

    bool m_isTimeSeries;
    bool m_isTimeSeriesHasBeenSet = false;
  };

} // namespace Model
} // namespace IoTTwinMaker
} // namespace Aws
