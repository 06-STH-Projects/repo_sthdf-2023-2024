# Web Parser and Full-Text Searcher for Plant and Flower Classification: Project Outcomes

## Introduction

The Web Parser and Full-Text Searcher project was developed to address the need for efficient and automated extraction of botanical data from the web. This Python-based console application is designed to crawl relevant databases and web pages, extract information on plant and flower classification, and provide a full-text search functionality. This document outlines the project's objectives, methodologies, and outcomes.

## Project Overview

The primary goal of this project was to create a tool that enables users to gather and search through botanical data efficiently. The application is particularly useful for researchers, botanists, and enthusiasts in the field of plant and flower classification.

![Business use](https://i.ibb.co/D9PQ0wq/business.jpg)

### Application components

![Application components](https://i.ibb.co/T1QHPfN/comp.jpg)

### Challenges

One of the main challenges was sourcing a database with plaintext data suitable for scraping and parsing. I had to navigate around javascript-based obfuscators, which are commonly used to prevent automated data extraction. The solution involved brute scraping and parsing techniques.

The second challenge was limitation of the Colab environment and issues with some libraries for indexing, which required adjustment of the software toolkit.

## Methodology

### Data Scraping and Parsing

- **Library Selection**: The `requests_html` library was chosen for its ability to bypass page bans typically encountered with standard scraping tools.
- **Data Extraction Process**:
  - Iterated through an alphabetical index of plant names.
  - Scraped links and HTML codes from each page.
  - Used regular expressions to isolate and extract the article body.
  - Parsed plaintext sections for CSV storage.

### Data Organization

- **CSV Creation**: Extracted data was organized into a CSV format, with non-plaintext content removed.
- **Indexing with Whoosh**: The dataset was indexed using Whoosh, a Python-based library, to facilitate efficient searching (and mitigate Colab issues with Lucene).

### Schema Design

The schema for the dataset includes the following fields: latin_name, common_name, family, hazards, habitats, regions, physical_characteristics, synonyms, edible_uses, medicinal_uses, other_uses, cultivation_details, propagation, and other_names.

### Search Functionality

- **Multi-field Parser with Field-Boosting**: Implemented to prioritize search results based on field relevance.
- **Ranking Algorithm**: BM25F algorithm was used for its reliability over TF-IDF in the Colab environment.
- **Query Syntax**: Supports simple keyword queries, such as “rose”, or more complex, as “rose europe”. Boolean queries are also available: “europe AND rose”, “europe OR rose”. And field-specific queries, such as: “regions:europe AND marigold” (AND/OR are case-sensitive).

## Use Cases

There are only 2 use cases for this whole app: 

1. Scrap and parse the web database thus updating the application knowledge base.
2. Search for data in the stored knowledge base.

### Use Case Diagram

![Use Case Diagram](https://mermaid.pyxl.uk/file_1702864620953.png)

## Application Demo Example

![Application Demo](https://i.ibb.co/7GZZC7m/Capture.png)

## Application Architecture Overview

The application consists of 2 separate modules: preparatory and execution.

![Modules](https://i.ibb.co/FmR2FTH/modules.png)

### Preparatory Module

#### Purpose and Functionality

- **Data Scraping and Parsing**: This module is responsible for the initial phase of the application, which involves scraping data from specified web pages and databases. It uses advanced scraping techniques to navigate through javascript-based obfuscators and extract plaintext data.
- **Data Processing and Indexing**: After scraping, the data is parsed, organized into a structured CSV format, and then indexed for efficient searching. This process involves cleaning the data to ensure accuracy and relevance.

#### Advantages

- **Efficiency in Data Management**: By separating the data preparation tasks, the Preparatory Module allows for a one-time, intensive data processing operation. This approach minimizes the computational load during the search phase.
- **Flexibility in Data Updating**: The module can be run independently to update or refresh the dataset as needed, without interfering with the search functionality.

#### Component Diagram

![Component Diagram](https://mermaid.pyxl.uk/file_1702888970399.png)

### Executional Module

#### Purpose and Functionality

- **User Interface and Search Execution**: This module is the user-facing part of the application. It provides a Command Line Interface (CLI) where users can input their search queries.
- **Data Retrieval and Display**: Leveraging the indexed data prepared by the Preparatory Module, it executes the search queries and displays the results to the user in an organized manner.

#### Advantages

- **User-Friendly Interaction**: By focusing solely on search execution and results display, the Executional Module offers a streamlined and user-friendly experience.
- **Operational Efficiency**: As it relies on pre-processed and indexed data, the search process is fast and efficient, enhancing the overall performance of the application.

#### Component Diagram

![Component Diagram](https://mermaid.pyxl.uk/file_1702888997075.png)

### Integration of Modules

The two modules, though distinct in their functionalities, are tightly integrated to ensure seamless operation. The Preparatory Module feeds its processed and indexed data into a shared folder, which the Executional Module accesses to perform search operations. This design ensures that the heavy lifting of data processing does not burden the search process, allowing for quick and responsive user interactions.

### Architecture Diagram

![Architecture Diagram](https://mermaid.pyxl.uk/file_1702860789611.png)

### Technical Flow Diagrams

#### Preparatory Module

![Technical Diagram for Preparatory Module](https://mermaid.pyxl.uk/file_1702860815339.png)

This diagram details the technical flow within the Preparatory Module, from web scraping to data indexing.

#### Executional Module

![Technical Diagram for Executional Module](https://mermaid.pyxl.uk/file_1702860834057.png)

This diagram outlines the technical process within the Executional Module, focusing on user query input, search execution, and displaying results.

### Sequence Diagrams

#### Preparatory Module

![Sequence Diagram for Preparatory Module](https://mermaid.pyxl.uk/file_1702860500307.png)

Illustrates the sequence of operations in the Preparatory Module, from web scraping to indexing.

#### Executional Module

![Sequence Diagram for Executional Module](https://mermaid.pyxl.uk/file_1702860508210.png)

Shows the sequence of interactions in the Executional Module, detailing user query processing and result display.

### Activity Diagram

![Activity Diagram](https://mermaid.pyxl.uk/file_1702888832071.png)

### Data Flow Diagram

![Data Flow Diagram](https://mermaid.pyxl.uk/file_1702864685985.png)

This diagram represents the flow of data in the Executional Module, from user input through the CLI interface to the display of search results.

## Conclusion

The project successfully developed a tool that scrapes, parses, and indexes botanical data from a public database. The application's CLI interface utilizes multi-field parsing with field-boosting, ensuring relevant and prioritized search results. The dataset's free-form nature, sourced from a community-driven database, presented challenges in standardizing precision and recall metrics. However, the application effectively addresses the need for efficient data gathering and searching in the field of plant and flower classification.

## Knowledge Acquired

Despite being a convenient environment, Google Colab has its own strict limitations regarding environment variables, versions of specific libraries outside of the scope of its downloadable repository, and is extremely unfriendly towards modification of components on a virtual OS level.

Thus, to mitigate compatibility and functionality issues for some software components, like the indexer, I had to move from faster and more cost-efficient options to more Colab-friendly ones. For example, from the Java-python hybrid Lucene/pyLucene to purely pythonic Whoosh. However, the price was a 2x slowdown of the indexing process.

If HTML files or dumps are relatively big (900+ megabytes per file), Colab will choke on them during complex processing, so a better solution is to either dissect them into smaller files manually or by using Apache Spark.

## Further Development Suggestions

- Using Apache Spark for parallel processing of a vast number of huge files from databases or dumps.
- Web-based GUI.
