#include <fstream>
#include <iostream>
#include <numeric>

int main()
{
    std::ifstream f("/tmp/0_water_dE_total.raw");
    if (!f.good())
        return 1;
    const unsigned short nX = 200;
    const unsigned short nY = 200;
    const unsigned short nZ = 350;
    const double lX = 100.; // mm
    const double lY = 100.; // mm
    const double lZ = 350.; // mm
    double* rawData = new double[static_cast<unsigned int>(nX)*nY*nZ];
    const unsigned int fileBytes = static_cast<unsigned int>(nX)*nY*nZ*8;
    f.read(reinterpret_cast<char*>(rawData), fileBytes);
    f.close();
    // Work with rawData
    for(unsigned short k = 0; k < nZ; ++k)
    {
        const double mean = std::accumulate(rawData+static_cast<unsigned int>(k)*nX*nY, rawData+static_cast<unsigned int>(k+1)*nX*nY, 0.)/nX/nY;
        std::cout << mean << std::endl;
    }
    delete[] rawData;
    return 0;
}
