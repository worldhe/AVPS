package com.whh.avps;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    String filesPath = null;
    String fileName  = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        filesPath = this.getFilesDir().getPath() + "/";
        fileName  = "Simpson.mp4";
        new Thread(new Runnable() {
            @Override
            public void run()
            {
                Utils.CopyAssetFileToDataDataFiles(MainActivity.this, filesPath, fileName);
                printfInfo(filesPath + fileName);
            }
        }).start();

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        printfVersion();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native void printfVersion();
    public native void printfInfo(String name);
}