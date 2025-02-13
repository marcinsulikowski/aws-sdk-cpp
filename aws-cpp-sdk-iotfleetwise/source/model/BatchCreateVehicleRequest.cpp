﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/iotfleetwise/model/BatchCreateVehicleRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::IoTFleetWise::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

BatchCreateVehicleRequest::BatchCreateVehicleRequest() : 
    m_vehiclesHasBeenSet(false)
{
}

Aws::String BatchCreateVehicleRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_vehiclesHasBeenSet)
  {
   Array<JsonValue> vehiclesJsonList(m_vehicles.size());
   for(unsigned vehiclesIndex = 0; vehiclesIndex < vehiclesJsonList.GetLength(); ++vehiclesIndex)
   {
     vehiclesJsonList[vehiclesIndex].AsObject(m_vehicles[vehiclesIndex].Jsonize());
   }
   payload.WithArray("vehicles", std::move(vehiclesJsonList));

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection BatchCreateVehicleRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "IoTAutobahnControlPlane.BatchCreateVehicle"));
  return headers;

}




