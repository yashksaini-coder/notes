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