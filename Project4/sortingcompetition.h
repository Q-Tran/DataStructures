#include <string>
#include <vector>

class SortingCompetition{
private:
	std::string fileName;
	std::vector<std::string> words;
	std::vector<std::string> vcopy;
	void quick(std::vector<std::string>& arr, int left, int right);

public:
	SortingCompetition();
	SortingCompetition(const std::string& inputFileName);
	void setFileName(const std::string& inputFileName);
	bool readData();
	bool prepareData();
	void sortData();
	void outputData(const std::string& outputFileName);
};