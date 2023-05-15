cp ~/template.cpp "./$1.cpp"
curl --output samples.zip "https://open.kattis.com/problems/$1/file/statement/samples.zip"
unzip samples.zip -d secret
rm samples.zip
