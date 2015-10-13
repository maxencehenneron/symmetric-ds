/**
 * Licensed to JumpMind Inc under one or more contributor
 * license agreements.  See the NOTICE file distributed
 * with this work for additional information regarding
 * copyright ownership.  JumpMind Inc licenses this file
 * to you under the GNU General Public License, version 3.0 (GPLv3)
 * (the "License"); you may not use this file except in compliance
 * with the License.
 *
 * You should have received a copy of the GNU General Public License,
 * version 3.0 (GPLv3) along with this library; if not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#ifndef SYM_DATA_EXTRACTOR_SERVICE_H
#define SYM_DATA_EXTRACTOR_SERVICE_H

#include <stdio.h>
#include "model/Node.h"
#include "model/OutgoingBatch.h"
#include "service/NodeService.h"
#include "transport/TransportManager.h"
#include "transport/OutgoingTransport.h"
#include "io/writer/ProtocolDataWriter.h"
#include "io/reader/ExtractDataReader.h"
#include "util/List.h"

typedef struct SymDataExtractorService {
    SymNodeService *nodeService;
    SymList * (*extract)(struct SymDataExtractorService *this, SymNode *node, SymOutgoingTransport *transport);
    void (*destroy)(struct SymDataExtractorService *this);
} SymDataExtractorService;

SymDataExtractorService * SymDataExtractorService_new(SymDataExtractorService *this, SymNodeService *nodeService);

#endif
