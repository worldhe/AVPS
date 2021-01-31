package com.whh.avps;

import android.content.Context;
import android.content.res.AssetManager;
import android.util.Log;

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

class Utils
{
    private static final String TAG = "Utils";

    static void CopyAssetFileToDataDataFiles(Context context, String filesPath, String fileName)
    {
        Log.d(TAG, "CopyAssetFileToDataDataFiles()");
        AssetManager asset    = context.getAssets();
        InputStream is        = null;
        try
        {
            is = asset.open(fileName);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }

        InputStreamReader isr = new InputStreamReader(is);
        BufferedReader br     = new BufferedReader(isr);
        FileWriter fw         = null;

        try
        {
            fw = new FileWriter(filesPath + fileName);
        }
        catch (IOException e)
        {
            e.printStackTrace();
            try
            {
                if (fw != null)
                {
                    fw.close();
                }

                if (br != null)
                {
                    br.close();
                }

                if (isr != null)
                {
                    isr.close();
                }

                if (is != null)
                {
                    is.close();
                }
            }
            catch (IOException ioException)
            {
                ioException.printStackTrace();
            }
        }

        String s = null;
        try
        {
            while ((s = br.readLine()) != null)
            {
                fw.write(s);
            }
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        finally
        {
            try
            {
                if (fw != null)
                {
                    fw.close();
                }

                if (br != null)
                {
                    br.close();
                }

                if (isr != null)
                {
                    isr.close();
                }

                if (is != null)
                {
                    is.close();
                }
            }
            catch (IOException ioException)
            {
                ioException.printStackTrace();
            }
        }
    }
}
