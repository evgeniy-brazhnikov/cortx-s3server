/*
 * COPYRIGHT 2015 SEAGATE LLC
 *
 * THIS DRAWING/DOCUMENT, ITS SPECIFICATIONS, AND THE DATA CONTAINED
 * HEREIN, ARE THE EXCLUSIVE PROPERTY OF SEAGATE TECHNOLOGY
 * LIMITED, ISSUED IN STRICT CONFIDENCE AND SHALL NOT, WITHOUT
 * THE PRIOR WRITTEN PERMISSION OF SEAGATE TECHNOLOGY LIMITED,
 * BE REPRODUCED, COPIED, OR DISCLOSED TO A THIRD PARTY, OR
 * USED FOR ANY PURPOSE WHATSOEVER, OR STORED IN A RETRIEVAL SYSTEM
 * EXCEPT AS ALLOWED BY THE TERMS OF SEAGATE LICENSES AND AGREEMENTS.
 *
 * YOU SHOULD HAVE RECEIVED A COPY OF SEAGATE'S LICENSE ALONG WITH
 * THIS RELEASE. IF NOT PLEASE CONTACT A SEAGATE REPRESENTATIVE
 * http://www.seagate.com/contact
 *
 * Original author:  Kaustubh Deorukhkar   <kaustubh.deorukhkar@seagate.com>
 * Original creation date: 10-Nov-2015
 */

#include "s3_api_handler.h"

std::shared_ptr<S3APIHandler>
S3APIHandlerFactory::create_api_handler(S3ApiType api_type,
          std::shared_ptr<S3RequestObject> request,
          S3OperationCode op_code) {
  std::shared_ptr<S3APIHandler> handler;

  switch(api_type) {
    case S3ApiType::service:
      handler = std::make_shared<S3ServiceAPIHandler> (request, op_code);
      break;
    case S3ApiType::bucket:
      handler = std::make_shared<S3BucketAPIHandler> (request, op_code);
      break;
    case S3ApiType::object:
      handler = std::make_shared<S3ObjectAPIHandler> (request, op_code);
      break;
    default:
      break;
  };
  return handler;
}