Web Parser and Full-Text Searcher for Plant and Flower Classification

The Web Parser and Full-Text Searcher for Plant and Flower Classification is a Python-based console application designed to automate the extraction and searching of web content specifically related to plant and flower classification. This tool is intended for use by individuals who need to gather and search through botanical data efficiently.

Contributor:

S041 Dennis Sobolev

1. Vision and Strategy

The vision for this project is to create a streamlined Python application that can autonomously crawl relevant databases and web pages, extract pertinent information on plant and flower classification, and provide a full-text search functionality to sort and display this information based on user queries.

The strategy to achieve this vision includes:

Developing a web crawler to systematically browse plant and flower databases and web pages

Scraping the full HTML code of these pages and downloading them

Utilizing regular expressions to parse the HTML and extract meaningful plain text, organizing the parsed text into structured CSV files

Implementing a full-text search system to sort and list relevant articles based on keyword relevancy

2. Goals and Expected Results

The goal is to successfully develop a functional Python console application that meets the project's requirements without the need for a graphical user interface. The expected result is a tool that allows the user to input keywords or sentences and receive a list of relevant parsed articles, sorted by relevancy.

The project roadmap is as follows:

Research and select the appropriate libraries and frameworks for web crawling and parsing

Develop the web crawler to target specific databases and web pages related to plant and flower classification

Implement the scraping and parsing mechanisms to process the HTML content

Design the data structure for the CSV file and implement the saving mechanism

Create the full-text search functionality to work with the parsed data

Test the application with various keywords to ensure functionality and accuracy

Main project risks include:

Ensuring the web crawler respects the terms of service and robots.txt files of target websites

Handling the variety of HTML structures to ensure reliable text extraction

Developing a robust full-text search algorithm that can efficiently sort and display results

3. Solution Scheme Draft

The application will be a command-line interface (CLI) program that performs the following tasks:
https://systemthinking-in-it.atlassian.net/9b3ce59e-eb0e-477b-985c-78b536f23a57#media-blob-url=true&id=afb84d28-e611-4d5c-844f-f8f55867ba78&collection=contentId-61374468&contextId=61374468&height=600&width=347&alt=


Web Crawler: This component will navigate to specified web pages and databases, focusing on plant and flower classification content.

HTML Scraper: This component will download the HTML content of the pages and store it locally.

Text Parser: Using regular expressions, this component will parse the HTML to extract plain text.

Data Organizer: The parsed text will be dissected into "Title", "Text Body", and "Supplementary Links", and then saved into a CSV file.

Full-Text Searcher: This component will allow the user to input search terms and will return a sorted list of articles based on relevancy from the CSV file.

This console application will be developed, tested, and verified for functionality.