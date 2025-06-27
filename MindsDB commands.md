---
tags:
  - python
  - mindsdb
---
---
# Generative AI tables 101

#### Our goal is to create an AI Table with Gemini Provider and Using **HackerNews** Data

- Making a ML engine

``` sql
CREATE ML_ENGINE google_gemini_engine
FROM google_gemini
USING
	api_key = 'your-gemini-api-key-here';
```

#### Create the AI Table for Text Summarization

Now create an AI table (model) that will generate summaries:

``` sql
CREATE MODEL story_summarizer
PREDICT summary
USING
    engine = 'google_gemini_engine',
    question_column = 'story',
    model_name = 'gemini-2.0-flash';
```

#### Connect to HackerNews

Set up the **HackerNews** integration:

```sql
CREATE DATABASE my_hackernews
WITH ENGINE = 'hackernews';
```

This creates a database with access to the `stories`, `hnstories` and `comments` tables from **HackerNews**.

#### Test the HackerNews Connection

Let's first explore the available data:

```sql
-- View some stories from HackerNews
SELECT *
FROM my_hackernews.stories
LIMIT 5;
```

#### ### Generate Summaries for HackerNews Stories

Now you can use your AI table to generate summaries for the HackerNews stories:

```sql
-- Generate summaries for recent HackerNews stories
SELECT 
    hn.title,
    hn.url,
    hn.score,
    ai.summary
FROM my_hackernews.hnstories AS hn
JOIN story_summarizer AS ai
WHERE hn.title IS NOT NULL
LIMIT 10;
```