---
tags:
  - rag
---
---

Retrieval Augmented Generation (RAG) is a technique that combines the information retrieval with `LLM` Large Language Model generation to improve the accuracy & relevance of the generated text.

- It works by retrieving relevant information from an external knowledge base and then using that information to augment the LLM's response, making it more grounded in evidence and context. 

#### Key Components of RAG:

- **Ingestion (Indexing):** This phase involves extracting, cleaning, and organizing data from various sources (like documents, databases, or APIs) and preparing it for retrieval. 

- **Retrieval:** A search algorithm is used to find the most relevant pieces of information from the indexed data based on the user's query. 

- **Generation:** The LLM uses the retrieved context and its own knowledge to generate a response that is both accurate and relevant to the user's query.

#### How RAG Works:

- **Data Ingestion:** The RAG system first ingests and indexes relevant data from external sources.

- **Retrieval:** When a user asks a question, the RAG system uses a retriever (like a vector database) to find the most relevant chunks of information from the indexed data. 
 
- **Generation:** The retrieved information is then fed to the LLM, which uses it to generate an answer that is both accurate and contextually relevant.

[[Basic RAG.excalidraw]]