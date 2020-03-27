#include "Data.h"


Data::Data() {
}
void Data::setArticle_cat(string Art_cat) {
	this->Article_Category = Art_cat;
	//cout << "added Category into Data object " << this->Article_Category << endl;
}
void Data::setArticle_Title(string Art_Title) {
	this->Article_Title = Art_Title;
	//cout << "added Title into Data object " << this->Article_Title << endl;
}
void Data::setDate_published(string Date_pub) {
	this->Date_Published = Date_pub;
	//cout << "added Date into Data object " << this->Date_Published << endl;
}

string Data::getArticle_cat() {

	return this->Article_Category;
}
string Data::getArticle_Title() {
	return this->Article_Title;
}
string Data::getDate_published() {
	return this->Date_Published;
}

