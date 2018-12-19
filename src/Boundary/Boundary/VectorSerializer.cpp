#include "stdafx.h"
#include "VectorSerializer.h"
#include "Logging.h"


Vector VectorSerializer::Load(const std::filesystem::path& path) const
{
	try
	{
		std::ifstream inputFile{ path.string() };
		size_t size{ 0 };  // elements count
		
		inputFile >> size;

		std::istream_iterator<double> inputIterator{ inputFile };
						
		Vector v(size);
		boost::algorithm::copy_n(inputIterator, size, v.begin());
				
		BoostLog(info, "Vector of size " + std::to_string(size) + " successfully loaded from file \"" +
			path.string() + "\"");
		return v;
	}
	catch (...) {
		std::string message = "Could not load vector from file \"" + path.string() + "\"";
		BoostLog(error, message);
		throw message;
	}
}


void VectorSerializer::Save(const std::filesystem::path& path, const Vector& vector) const
{
	try
	{
		std::ofstream outputFile{ path.string() };

		outputFile << vector.size() << std::endl;

		std::ostream_iterator<double> outIterator{ outputFile, " " };
		boost::algorithm::copy_n(vector.begin(), vector.size(), outIterator);
						
		BoostLog(info, "Vector of size " + std::to_string(vector.size()) + " successfully saved to file \"" + path.string() + "\"");
	}
	catch (...) {
		std::string message = "Could not save vector to file \"" + path.string() + "\"";
		BoostLog(error, message);
		throw message;
	}
} 
