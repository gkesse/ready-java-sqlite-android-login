package com.readydev.app;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class GSQLite extends SQLiteOpenHelper {
    private static final String DBNAME = "db_readyapp.dat";
    private long m_id = -1;

    public GSQLite(Context _context) {
        super(_context, DBNAME, null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase _dbSQL) {
        _dbSQL.execSQL("" +
                "create table _users ( " +
                "_id integer primary key autoincrement " +
                ", _username text not null " +
                ", _password text not null " +
                ", unique(_username) " +
                ")");
    }

    @Override
    public void onUpgrade(SQLiteDatabase _dbSQL, int _oldVersion, int _newVersion) {
        _dbSQL.execSQL("drop table if exists _users");
    }

    public long getId() {
        return m_id;
    }

    public Boolean insertData(String _table, ContentValues _values) {
        SQLiteDatabase dbSQL = this.getWritableDatabase();
        m_id = dbSQL.insert(_table, null, _values);
        if(m_id == -1) return  false;
        return true;
    }

    public String  readData(String _sql, String[] _params) {
        SQLiteDatabase dbSQL = getWritableDatabase();
        Cursor lCursor = dbSQL.rawQuery(_sql, _params);
        String lData = "";
        if(lCursor.moveToFirst()) {
            lData = lCursor.getString(0);
        }
        return lData;
    }

    public List<List<String>> readMap(String _sql, String[] _params) {
        SQLiteDatabase dbSQL = getWritableDatabase();
        Cursor lCursor = dbSQL.rawQuery(_sql, _params);
        List<List<String>> lMap = new ArrayList<>();
        if(lCursor.moveToFirst()) {
            List<String> lRow = new ArrayList<>();
            do {
                for(int i = 0; i < lCursor.getColumnCount(); i++) {
                    String lData = lCursor.getString(i);
                    lRow.add(lData);
                }
                lMap.add(lRow);
            } while (lCursor.moveToNext());
        }
        return lMap;
    }
}
