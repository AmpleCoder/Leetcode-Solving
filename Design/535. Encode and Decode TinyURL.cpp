/*
my solution it's fairly simple to understand
*/

class Solution {
public:
    unordered_map<string,string> encoded,decoded;
    int id;
    
    Solution(){
        id=0;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string encodedUrl;
        id++;
        encodedUrl="http://tinyurl.com/"+to_string(id);
        encoded[longUrl]=encodedUrl;
        decoded[encodedUrl]=longUrl;
        
        return encodedUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decoded[shortUrl];
    }
};


/*
most proper way to do this 
note: if in a constructor we don't use srand(time(0)) then result for other string will be same (why?)

Performance Analysis

The number of URLs that can be encoded is quite large in this case, nearly of the order (10+26)^6 

The length of the encoded URLs is fixed to 6 units, which is a significant reduction for very large URLs.

The performance of this scheme is quite good, due to a very less probability of repeated same codes generated.

We can increase the number of encodings possible as well, by increasing the length of the encoded strings. Thus, there exists a tradeoff between the length of the code and the number of encodings possible.

Predicting the encoding isn't possible in this scheme since random numbers are used.

*/

class Solution {
    unordered_map<string,string> encoded;
    string magicString;
    int size;
    int encodeSize;
    
    string getRandString(int index=0){
        if(index>encodeSize){
            return "";
        }
        
        int randInt=rand();
        return magicString[randInt%size]+getRandString(index+1);
    }
    
public:
    Solution(){
        magicString="0123456789abcdefghijklmnopqrstuvwxyz";
        size=magicString.size();
        encodeSize=6;
        srand(time(0));
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string encodedUrl="http://tinyurl.com/",lastPartRandomString;
        lastPartRandomString=getRandString();
        
        while(encoded.count(lastPartRandomString)){
            lastPartRandomString=getRandString();
        }
        
        encodedUrl+=lastPartRandomString;
        encoded[encodedUrl]=longUrl;
        // cout<<encodedUrl<<endl;
        return encodedUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return encoded[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));