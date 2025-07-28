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

#### Generate Summaries for HackerNews Stories

Now you can use your AI table to generate summaries for the HackerNews stories:

```sql
-- Generate summaries for recent HackerNews stories
SELECT 
    hn.title,
    hn.url,
    hn.score,
    ai.summary
FROM my_hackernews.stories AS hn
JOIN story_summarizer AS ai
WHERE hn.title IS NOT NULL
LIMIT 10;
```

### Advanced Usage - Summarizing with Context

If you want to include more context in your summaries, you can create a model that uses multiple fields:

```sql
CREATE MODEL detailed_hn_summarizer
PREDICT detailed_summary
USING
    engine = 'google_gemini_engine',
    model_name = 'gemini-2.0-flash',
    prompt_template = 'Summarize this HackerNews story. Title: {{title}}. URL: {{url}}. Score: {{score}}. Provide a brief, informative summary focusing on the technical content and significance.';
```

Then query it like this:

```sql
SELECT 
    hn.title,
    hn.url,
    hn.score,
    ai.detailed_summary
FROM my_hackernews.stories AS hn
JOIN detailed_hn_summarizer AS ai
WHERE hn.score > 100  -- Only high-scoring stories
LIMIT 5;
```

#### Query Individual Stories

You can also generate summaries for specific stories:

```sql
SELECT story, summary
FROM story_summarizer
WHERE story = 'Your specific HackerNews story title or text here';
```

## Key Points to Remember

1. **API Key**: Make sure you have a valid Google Gemini API key
2. **Rate Limits**: Be mindful of API rate limits when processing large batches
3. **Data Fields**: The HackerNews integration provides fields like `title`, `url`, `score`, `text`, etc.
4. **Model Flexibility**: You can customize the `prompt_template` to get different types of summaries

---
