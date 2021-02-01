# AVPS




ffmpeg问题归纳
    1.在掉调用avformat_alloc_context()函数时，总是返回负值。例如-2，-13。
      很有可能时SLinux权限问题，调试的时候可以通过adb shell将SLinux临时关闭。
      adb shell setenforce 0 //设置成permissive模式（宽容的）
      adb shell setenforce 1 //设置成enforce 模式（强制的）