package com.braincs.eglcamera;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

/**
 * Created by Shuai
 * 4/8/21.
 */
public class MainActivity extends Activity {
    private Button start_preview_btn;
    static {
        System.loadLibrary("songstudio");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        start_preview_btn = (Button) findViewById(R.id.start_preview);
        start_preview_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, CameraPreviewActivity.class);
                startActivity(intent);
            }
        });
    }

}
