package com.pscomp.EncryptTest;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.security.InvalidKeyException;
import java.security.Key;
import java.security.NoSuchAlgorithmException;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.KeyGenerator;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class EncryptTest extends Activity {
    private static final String TAG = "EncryptTest";
    private static final boolean DEBUG = true;

    private EditText mInputBox;
    private EditText mOutputBox;
    private Button mEncryptBtn;

    private Cipher mCipher;
    private KeyGenerator mKeyGenerator;
    private String mTransformation = "AES/CBC/PKCS5Padding";
    private Key mKey;

    private BufferedInputStream mBis;
    private BufferedOutputStream mBos;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_encrypt_test);
        try {
            init();
        } catch (NoSuchAlgorithmException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (NoSuchPaddingException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        keyGenerator();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.activity_encrypt_test, menu);
        return true;
    }

    private void init() throws NoSuchAlgorithmException, NoSuchPaddingException {
        if (DEBUG) {
            Log.d(TAG, "EncryptTest Conponents Initializing...");
        }
        View.OnClickListener listener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                if (DEBUG) {
                    Log.d(TAG, "Setting onClickListener...");
                }
                encrypt();
            }
        };
        mInputBox = (EditText) findViewById(R.id.inputBox);
        mOutputBox = (EditText) findViewById(R.id.outputBox);
        mEncryptBtn = (Button) findViewById(R.id.encryptButton);
        mEncryptBtn.setOnClickListener(listener);

        mCipher = Cipher.getInstance(mTransformation);
        mKeyGenerator = KeyGenerator.getInstance("AES");
        
    }

    private void keyGenerator() {
        mKey = mKeyGenerator.generateKey();
    }

    private void encrypt() {
        String input = getInputBoxContent();
        try {
            mCipher.init(Cipher.ENCRYPT_MODE, mKey);
        } catch (InvalidKeyException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        }
        byte[] inputBytes = input.getBytes();               //plain
        byte[] outputBytes = new byte[1024];
        try {
            outputBytes = mCipher.doFinal(inputBytes);
        } catch (IllegalBlockSizeException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (BadPaddingException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }   //encrypt
        String outputContent = outputBytes.toString();
        setOutputBoxContent(outputContent);
    }

    private String getInputBoxContent() {
        String content = mInputBox.getText().toString();
        return content;
    }

    private void setOutputBoxContent(String outputContent) {
        mOutputBox.setText(outputContent);
    }
}
