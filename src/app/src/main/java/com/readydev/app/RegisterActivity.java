package com.readydev.app;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.google.android.material.textfield.TextInputEditText;

public class RegisterActivity extends AppCompatActivity {
    TextInputEditText ui_edtUsername;
    TextInputEditText ui_edtPassword;
    TextInputEditText ui_edtConfirm;
    Button ui_btnRegister;
    ImageView ui_imgReturn;
    TextView ui_txtLogin;
    GLog m_logs;
   GRegister m_register;
    GSQLite m_dbSQL;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        ui_edtUsername = findViewById(R.id.edtUsername);
        ui_edtPassword = findViewById(R.id.edtPassword);
        ui_edtConfirm = findViewById(R.id.edtConfirm);
        ui_btnRegister = findViewById(R.id.btnRegister);
        ui_imgReturn = findViewById(R.id.imgReturn);
        ui_txtLogin = findViewById(R.id.txtLogin);

        m_logs = new GLog();
        m_register = new GRegister();
        m_dbSQL = new GSQLite(getApplicationContext());

        m_logs.setContext(getApplicationContext());
        m_register.setSQLite(m_dbSQL);

        initActivity();

        ui_btnRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                m_register.setUsername(ui_edtUsername.getText().toString());
                m_register.setPassword(ui_edtPassword.getText().toString());
                m_register.setConfirm(ui_edtConfirm.getText().toString());

                if(!m_register.onRegister()) {
                    m_logs.showMessage(m_register.getLogs().getErrors());
                    return;
                }

                m_logs.showMessage("Votre compte a été créé.");

                Intent lIntent = new Intent(getApplicationContext(), HomeActivity.class);
                lIntent.putExtra("id", m_register.getId());
                lIntent.putExtra("username", ui_edtUsername.getText().toString());
                startActivity(lIntent);
            }
        });

        ui_imgReturn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent lIntent = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(lIntent);
            }
        });

        ui_txtLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent lIntent = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(lIntent);
            }
        });
    }

    public void initActivity() {
        String lUsername = getIntent().getExtras().getString("username");
        String lPassword = getIntent().getExtras().getString("password");
        ui_edtUsername.setText(lUsername);
        ui_edtPassword.setText(lPassword);
    }
}