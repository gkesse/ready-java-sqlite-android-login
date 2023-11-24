package com.readydev.app;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

public class HomeActivity extends AppCompatActivity {
    ImageView ui_imgLogout;
    TextView ui_txtUsername;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);

        ui_imgLogout = findViewById(R.id.imgLogout);
        ui_txtUsername = findViewById(R.id.txtUsername);

        initActivity();

        ui_imgLogout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent lIntent = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(lIntent);
            }
        });
    }

    public void initActivity() {
        long lId = getIntent().getExtras().getLong("id");
        String lUsername = getIntent().getExtras().getString("username");
        ui_txtUsername.setText(String.format("%s (%d)", lUsername, lId));
    }
}