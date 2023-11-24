package com.readydev.app;

import android.content.Context;
import android.widget.Toast;

import java.util.ArrayList;

public class GLog {
    private String m_type = "";
    private String m_msg = "";
    private ArrayList<GLog> m_map = new ArrayList<GLog>();
    private Context m_ctx = null;

    public void setContext(Context _ctx) {
        m_ctx = _ctx;
    }

    public void addError(String _msg) {
        GLog lObj = new GLog();
        lObj.m_type = "error";
        lObj.m_msg = _msg;
        m_map.add(lObj);
    }

    public void clear() {
        m_map.clear();
    }

    public Boolean hasErrors() {
        for (GLog lObj : m_map) {
            if(lObj.m_type.equals("error")) return true;
        }
        return false;
    }

    public String getErrors() {
        String lErrors = "";
        for (GLog lObj : m_map) {
            if(!lObj.m_type.equals("error")) continue;
            if(!lErrors.isEmpty()) lErrors += "\n";
            lErrors += lObj.m_msg;
        }
        return lErrors;
    }

    public void showMessage(String _msg) {
        if(m_ctx == null) return;
        Toast.makeText(m_ctx, _msg, Toast.LENGTH_LONG).show();
    }
}
