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
#include "db/sqlite/SqliteTriggerTemplate.h"

//#define SYM_SQL_INSERT_TRIGGER_TEMPLATE "\
//create trigger $(*triggerName) after insert on $(*schemaName)$(**tableName)    \n\
//for each row     \n\
//  when ($(**syncOnInsertCondition) and $(**syncOnIncomingBatchCondition))    \n\
//  begin    \n\
//    insert into sym_data (table_name, event_type, trigger_hist_id, row_data, channel_id, transaction_id, source_node_id, external_data, create_time)    \n\
//    values(    \n\
//           '$(**targetTableName)', \n\
//           'I', \n\
//           $(**triggerHistoryId), \n\
//           $(columns),    \n\
//           $(channelExpression), null, $(sourceNodeExpression), \n\
//           $(externalSelect),    \n\
//           strftime('%Y-%m-%d %H:%M:%f','now','localtime')    \n\
//    ); \n\
//        $(custom_on_insert_text) \n\
//end"

char * buildColumnsString(char *origTableAlias, char *tableAlias,
            char *columnPrefix, SymList *columns, SymDataEventType *dml, unsigned int isOld,
            SymChannel *channel, SymTrigger *trigger) {

    char *lastCommandToken = "||','||";

    int i = 0;
    for (i = 0; i < columns->size; i++) {
        SymColumn *column = columns->get(columns, i);

    }

    return 0;
}

char * SymSqliteTriggerTemplate_replaceTemplateVariables(SymSqliteTriggerTemplate *this, SymDataEventType *dml,
            SymTrigger *trigger, SymTriggerHistory *history, SymChannel *channel, char *tablePrefix,
            SymTable *table, char *defaultCatalog, char *defaultSchema, char *ddl) {
    char *triggerName = history->nameForInsertTrigger; // TODO
    char *schemaName = "";
    char *tableName = table->name;
    char *syncOnInsertCondition = trigger->syncOnInsertCondition;
    char *syncOnIncomingBatchCondition = "1"; // TODO
    char *targetTableName = trigger->sourceTableName; // TODO
    char *triggerHistoryId = SymStringUtils_format("%d", -1);


return 0;
}

char * SymSqliteTriggerTemplate_createTriggerDDL(SymSqliteTriggerTemplate *this, SymDataEventType *dml,
            SymTrigger *trigger, SymTriggerHistory *history, SymChannel *channel, char *tablePrefix,
            SymTable *originalTable, char *defaultCatalog, char *defaultSchema) {

    char *ddl;
    if (dml == SYM_DATA_EVENT_INSERT) {
        ddl = SYM_SQL_INSERT_TRIGGER_TEMPLATE;
    }

return 0;
}


void SymSqliteTriggerTemplate_destroy(SymSqliteTriggerTemplate *this) {

    free(this);
}

SymSqliteTriggerTemplate * SymSqliteTriggerTemplate_new(SymSqliteTriggerTemplate *this) {
    if (this == NULL) {
        this = (SymSqliteTriggerTemplate *) calloc(1, sizeof(SymSqliteTriggerTemplate));
    }
    this->createTriggerDDL = (void *) &SymSqliteTriggerTemplate_createTriggerDDL;
    this->destroy = (void *) &SymSqliteTriggerTemplate_destroy;
    return this;
}
