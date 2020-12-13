## OpenCV

* Requirements: Visual Studio 2015 and up, OpenCV libraries

### Installation

[OpenCV Releases]: opencv.org

1. Download libraries via ``VERSION 2.4.11`` ▶`` OpenCV for Windows``

2. Unzip downloaded files

3. Select Environment Path and add ``OPENCV_BUILD`` variable and set a value to ``C:\< downloaded path>\opencv\build`` 

4. Whenever generating a new project file, make sure to add the libraries listed down below.

   You can simply copy and paste these through ``Project attributes`` ▶ ``Linker`` ▶``Additional Dependencies``

```
opencv_calib3d2411d.lib
opencv_contrib2411d.lib
opencv_core2411d.lib
opencv_features2d2411d.lib
opencv_flann2411d.lib
opencv_gpu2411d.lib
opencv_highgui2411d.lib
opencv_imgproc2411d.lib
opencv_legacy2411d.lib
opencv_ml2411d.lib
opencv_nonfree2411d.lib
opencv_objdetect2411d.lib
opencv_ocl2411d.lib
opencv_photo2411d.lib
opencv_stitching2411d.lib
opencv_superres2411d.lib
opencv_video2411d.lib
opencv_videostab2411d.lib
```

5. Add  ``C:\< downloaded path>\opencv\build\include`` in ``Project attributes`` ▶ ``C/C++``   ▶ ``Additional Include Directory``
6. Add ``C:\< downloaded path>\opencv\build\x86\vc15\lib`` in ``Project attributes`` ▶ ``General``   ▶ ``Additional Library Directory``

