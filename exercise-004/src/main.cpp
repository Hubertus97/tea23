#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include "image.h"
#include <opencv2/opencv.hpp>

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::println("Größe des Image Arrays:{}", sizeof(image));

    fmt::print("Erstes Byte: 0x{:02x}\n", image[0]);

    
    cv::Mat Bild = cv::Mat(image_height, image_width, CV_8UC3, (void*)image);

    fmt::println("Breite des Bilds:{}", Bild.cols);
    fmt::println("Höhe des Bilds:{}", Bild.rows);
    fmt::println("Kanäle des Bilds:{}", Bild.channels());

    return 0; /* exit gracefully*/
}
