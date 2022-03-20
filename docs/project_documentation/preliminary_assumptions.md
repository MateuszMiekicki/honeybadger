## Description of the problem

The problem is the amount of invoices in paper form without a digital equivalent capable of extracting the data
automatically. The problem is currently being solved by a human (read manual entry of invoice fields). This has resulted
in a measly result per hour and the potential for that mistakes to be made.

## System goals

The main objective is to fully automate the digitizing of invoices, which will allow full integrity with the accounting
system. Another objective that is related to the first one is to save money.

## System context

The final product will consist of three independent components. Each component will be completely replaceable.

1. **SDK** - a set of methods allowing full separation from other modules. This solution is suitable for integration
   with already existing software.
2. **cloud computing** - with the idea that "there can be a lot of it", the processing of large packages will be done in
   the cloud (I'm far from specifying anything at this stage, but I'm heading towards GCP and CUDA). Of course this will
   be replaceable.
3. **GUI** - client so that the average user can use a ready-made solution.

The solution will be as cross-platform as possible. Definitely based on x86 architecture. So full access from Windows,
Linux and older Macs. By sharing the SDK and the BSD 0 license there will be full freedom in the use of the modules.
Nothing stands in the way of integrating it into a ready-made commercial product.

## System scope (functionality)

+ Recognition of an invoice from a file.
+ Recognising invoices via the webcam.
+ Extracts specific data from the invoice.
    - The data and their position are determined by the user when creating the template for the first time.
+ Export data to a selected format.
    - Ability to name fields in the exported file.
+ Data backup.
+ Possibility of using an automatic search for a format template from those available.
+ I was thinking about machine learning for automatic templating.
+ Management of saved invoices.
+ Reporting of irregularities.
+ Export invoice templates.

## Quality and other requirements

The project will be test-based. The whole build process will be based on CI and CD. Due to the fact that the system is
open source, and I don't intend to host it, finished packages will be delivered only. I will leave the evaluation of the
code quality to static analysis thanks to sonarqube.

The connection itself will be based on TLS. Data will be asymmetrically encrypted. Reliability and performance depends
strictly on the user's hardware.

## Structural vision

+ C++ 17
    - [Tesseract 4.y.z](https://github.com/tesseract-ocr/tesseract)
    - [OpenCV 4.y.z](https://github.com/opencv/opencv)
    - [spdlog 1.y.z](https://github.com/gabime/spdlog)
    - [Qt 6.y](https://www.qt.io/product/qt6)
    - [Google Test](https://github.com/google/googletest)
    - [Google benchmark](https://github.com/google/benchmark)
    - [OpenCL 3.y](https://www.khronos.org/opencl/)
    - [CUDA 11.y](https://developer.nvidia.com/)
+ CMake 3.18+
+ [Doxygen](https://github.com/doxygen/doxygen)
+ [CircleCI](https://circleci.com/)
    - [sonarqube](https://www.sonarqube.org/)

## Restrictions

## Glossary