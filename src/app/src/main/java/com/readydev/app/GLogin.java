package com.readydev.app;

public class GLogin extends GObject {
    private long m_id = 0;
    private String m_username;
    private String m_password;
    private GSQLite m_dbSQL = null;

    public void setUsername(String _username) {
        m_username = _username;
    }

    public void setPassword(String _password) {
        m_password = _password;
    }

    public void setSQLite(GSQLite _dbSQL) {
        m_dbSQL = _dbSQL;
    }

    public long getId() {
        return m_id;
    }

    public Boolean onLogin() {
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

        String lPassword = loadUsername();

        if(lPassword.isEmpty()) {
            getLogs().addError("Vous n'avez pas de compte.");
            return false;
        }
        if(!lPassword.equals(m_password)) {
            getLogs().addError("Le mot de passe est incorrect.");
            return false;
        }

        m_id = loadId();
        return !getLogs().hasErrors();
    }

    public String loadUsername() {
        String lPassword = m_dbSQL.readData("" +
                "select _password from _users " +
                "where _username = ? " +
                "", new String[]{m_username});
        return lPassword;
    }

    public long loadId() {
        long lId = Integer.parseInt(m_dbSQL.readData("" +
                "select _id from _users " +
                "where _username = ? " +
                "", new String[]{m_username}));
        return lId;
    }
}
