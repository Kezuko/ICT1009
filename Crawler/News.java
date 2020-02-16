package myPackage;

public interface News {
	void getPageLinks(String URL, int depth);
	void writeToFile(String filename);
}
