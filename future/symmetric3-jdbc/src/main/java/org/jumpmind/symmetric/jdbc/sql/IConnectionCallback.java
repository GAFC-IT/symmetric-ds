package org.jumpmind.symmetric.jdbc.sql;

import java.sql.Connection;
import java.sql.SQLException;

public interface IConnectionCallback<T> {

    public T execute(Connection con) throws SQLException;

}
