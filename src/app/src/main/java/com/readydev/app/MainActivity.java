package com.readydev.app;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.material.textfield.TextInputEditText;

//===============================================
public class MainActivity extends AppCompatActivity {

    Button ui_btnLogin;
    TextView ui_txtRegister;
    TextInputEditText ui_edtUsername;
    TextInputEditText ui_edtPassword;
    GLog m_logs;
    GLogin m_login;
    GSQLite m_dbSQL;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ui_btnLogin = findViewById(R.id.btnLogin);
        ui_txtRegister = findViewById(R.id.txtRegister);
        ui_edtUsername = findViewById(R.id.edtUsername);
        ui_edtPassword = findViewById(R.id.edtPassword);

        m_logs = new GLog();
        m_login = new GLogin();
        m_dbSQL = new GSQLite(getApplicationContext());

        m_logs.setContext(getApplicationContext());
        m_login.setSQLite(m_dbSQL);

        ui_btnLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                m_login.setUsername(ui_edtUsername.getText().toString());
                m_login.setPassword(ui_edtPassword.getText().toString());

                if(!m_login.onLogin()) {
                    m_logs.showMessage(m_login.getLogs().getErrors());
                    return;
                }

                m_logs.showMessage("Vous êtes connecté.");

                Intent lIntent = new Intent(getApplicationContext(), HomeActivity.class);
                lIntent.putExtra("id", m_login.getId());
                lIntent.putExtra("username", ui_edtUsername.getText().toString());
                startActivity(lIntent);
            }
        });

        ui_txtRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent lIntent = new Intent(getApplicationContext(), RegisterActivity.class);
                lIntent.putExtra("username", ui_edtUsername.getText().toString());
                lIntent.putExtra("password", ui_edtPassword.getText().toString());
                startActivity(lIntent);
            }
        });
    }
}
//===============================================
