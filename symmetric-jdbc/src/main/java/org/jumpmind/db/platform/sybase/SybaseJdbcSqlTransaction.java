package org.jumpmind.db.platform.sybase;

import org.jumpmind.db.model.Table;
import org.jumpmind.db.sql.JdbcSqlTemplate;
import org.jumpmind.db.sql.JdbcSqlTransaction;

public class SybaseJdbcSqlTransaction extends JdbcSqlTransaction {

    public SybaseJdbcSqlTransaction(JdbcSqlTemplate sqltemplate) {
        super(sqltemplate);
    }

    @Override
    public void allowInsertIntoAutoIncrementColumns(boolean allow, Table table, String quote) {
        if (table != null && table.getAutoIncrementColumns().length > 0) {
            if (allow) {
                execute(String.format("SET IDENTITY_INSERT %s ON",
                        table.getFullyQualifiedTableName(quote)));
            } else {
                execute(String.format("SET IDENTITY_INSERT %s OFF",
                        table.getFullyQualifiedTableName(quote)));
            }
        }
    }

}
