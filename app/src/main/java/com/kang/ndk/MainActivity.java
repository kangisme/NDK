package com.kang.ndk;

import android.Manifest;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        TextView myText = findViewById(R.id.my_text);
        myText.setText(myText());
        findViewById(R.id.file).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String path = MainActivity.this.getFilesDir().getPath() + "/kang.txt";
                saveText(path);
            }
        });
        findViewById(R.id.array).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int[] array = {1, 2, 3, 4, 5};
                operateArray(array);
                String text = array[0] + " " + array[1] + " " + array[2] + " " + array[3] + " " + array[4];
                Toast.makeText(MainActivity.this, text, Toast.LENGTH_SHORT).show();
            }
        });
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String myText();

    public native void saveText(String text);

    public native void operateArray(int[] array);
}
