#ifndef CPP_STRING_H
#define CPP_STRING_H


namespace string_toys {

auto reverse(const std::string& str) -> std::string {
	std::string rev="";
	for(int i=0;i<str.length();i++){
		rev+=str[str.length()-1-i];
	}
	return rev;
}

auto first_to_upper(const std::string& str) -> std::string {
	std::string result, word;
	result.reserve(str.length());
	bool a;
	//result="";
	/*result+=toupper(str[0]);
	for(int i=1;i<str.length();i++){
		result+=str[i];
	}*/
	for(int i=0;i<str.length();i++){
		word="";
		while(str[i]!=' ' and str[i]!='\n' and i<str.length()){
			word+=str[i];
			i++;
			//std::cout<<"str["<<i<<"]="<<str[i]<<"|"<<str.length()<<std::endl;
		}
		//std::cout<<"["<<word<<"]\n";
		word[0]=toupper(word[0]);
		//std::cout<<"{"<<word<<"}\n";

		result+=word;
		a=str[i]=='\n';
		//std::cout<<"<"<<str[i]<<">"<<a<<std::endl;
		if(str[i]==' ') result+=' ';
		else if(str[i]=='\n') result+='\n';
		//std::cout<<"> "<<result<<"\n";

	}
	return result;
}

auto count_vowels(const std::string& str) -> int {
    char vowels[]={'a','e','u','i','o','y'/*,'ą','ę','ó'*/};
	int counter=0;
	char *iterator;
	for(int i=0;i<str.length();i++){
		if(std::find(std::begin(vowels), std::end(vowels), str[i]) != std::end(vowels)) counter++;
	}
	return counter;
}

auto sum_digits(const std::string& str) -> int {
    int sum=0;
	for(int i=0;i<str.length();i++){
		if(isdigit(str[i])){
			sum+=(str[i]-48);
			//std::cout<<"\""<<str[i]<<"\""<<std::endl;
		}
	}
	return sum;
}

auto search_substr(const std::string& str, const std::string& substr) -> int {
	int result=-1;
	for(int i=0;i<str.length();i++){
		if(str[i]==substr[0]){
			result=i;
			i++;
			for(int j=1;j<substr.length();j++){
				if(str[i]!=substr[j]){
					result=-1;
					i--;
					break;
				}i++;
			}
			if(result>0)break;
		}
	}
	return result;
}

auto custom_serach(const char* str, const char* substr) -> int {
    int result=-1;
	int sub_iterator=0;
	//std::cout<<*str<<std::endl;
	for(int i=0;*(str+i)!='\0';i++){
		//std::cout<<"str["<<i<<"]="<<*(str+i)<<std::endl;
		if(*(str+i)==*(substr)){
			result=i;
			i++;
			sub_iterator=0;
			while(*(str+i+sub_iterator)!='\0'){
				//std::cout<<"str["<<sub_iterator+i<<"]="<<*(str+i+sub_iterator-1)<<" vs "<<*(substr+sub_iterator)<<std::endl;
				if(*(str+sub_iterator+i-1)!=*(substr+sub_iterator)){
					if(*(substr+sub_iterator)=='\0') break;
					result=-1;
					i--;
					break;
				}//i++;
				sub_iterator++;
			}i+=sub_iterator;
			//std::cout<<result<<std::endl;
			if(result>0)break;
		}
	}
	return result;
}

}  // namespace string_toys

#endif /* CPP_STRING_H */
