package com.readydev.app;

import android.content.ContentValues;

public class GRegister extends GObject {
    private long m_id = 0;
    private String m_username;
    private String m_password;
    private String m_confirm;
    private GSQLite m_dbSQL = null;

    public void setUsername(String _username) {
        m_username = _username;
    }

    public void setPassword(String _password) {
        m_password = _password;
    }

    public void setConfirm(String _confirm) {
        m_confirm = _confirm;
    }

    public void setSQLite(GSQLite _dbSQL) {
        m_dbSQL = _dbSQL;
    }

    public long getId() {
        return m_id;
    }

    public Boolean onRegister() {
        getLogs().clear();

        if(m_dbSQL == null) {
            getLogs().addError("Le serveur de données n'est pas initialisé.");
            return false;
        }
        if(m_username.isEmpty()) {
            getLogs().addError("Le nom d'utilisateur est obligatoire.");
            return false;
        }
        if(m_password.isEmpty()) {
            getLogs().addError("Le mot de passe est obligatoire.");
            return false;
        }
        if(m_confirm.isEmpty()) {
            getLogs().addError("La confirmation est obligatoire.");
            return false;
        }
        if(!m_password.equals(m_confirm)) {
            getLogs().addError("Les mots de passe sont différents.");
            return false;
        }

        String lPassword = loadUsername();

        if(!lPassword.isEmpty()) {
            getLogs().addError("Vous avez déjà un compte.");
            return false;
        }

        if(!insertUser()) {
            getLogs().addError("Le serveur de données est indisponible.");
            return false;
        }

        return !getLogs().hasErrors();
    }

    public String loadUsername() {
        String lPassword = m_dbSQL.readData("" +
                "select _password from _users " +
                "where _username = ? " +
                "", new String[]{m_username});
        return lPassword;
    }

    public Boolean insertUser() {
        ContentValues lContentValues = new ContentValues();
        lContentValues.put("_username", m_username);
        lContentValues.put("_password", m_password);
        if(m_dbSQL.insertData("_users", lContentValues)) {
            m_id = m_dbSQL.getId();
            return true;
        }
        return false;
    }
}
