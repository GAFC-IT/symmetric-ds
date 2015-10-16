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
#ifndef INC_DB_SQLITE_SQLITETRIGGERTEMPLATE_H_
#define INC_DB_SQLITE_SQLITETRIGGERTEMPLATE_H_

#include <stdlib.h>
#include "io/data/DataEventType.h"
#include "model/Trigger.h"
#include "model/TriggerHistory.h"
#include "model/Channel.h"
#include "db/model/Table.h"
#include "util/StringUtils.h"

typedef struct SymSqliteTriggerTemplate {
    char * (*createTriggerDDL)(struct SymSqliteTriggerTemplate *this, SymDataEventType *dml,
            SymTrigger *trigger, SymTriggerHistory *history, SymChannel *channel, char *tablePrefix,
            SymTable *originalTable, char *defaultCatalog, char *defaultSchema);
    void (*destroy)(struct SymSqliteTriggerTemplate *this);
} SymSqliteTriggerTemplate;

SymSqliteTriggerTemplate * SymSqliteTriggerTemplate_new(SymSqliteTriggerTemplate *this);

#define SYM_SQL_INSERT_TRIGGER_TEMPLATE "\
create trigger %s after insert on %s%s    \n\
for each row     \n\
  when (%s and %s)    \n\
  begin    \n\
    insert into sym_data (table_name, event_type, trigger_hist_id, row_data, channel_id, transaction_id, source_node_id, external_data, create_time)    \n\
    values(    \n\
           '%s', \n\
           'I', \n\
           %s, \n\
           %s, \n\
           %s, null, %s, \n\
           %s, \n\
           strftime('%Y-%m-%d %H:%M:%f','now','localtime')    \n\
    ); \n\
        %s \n\
end"

#endif /* INC_DB_SQLITE_SQLITETRIGGERTEMPLATE_H_ */
