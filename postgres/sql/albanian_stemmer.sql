CREATE EXTENSION albanian_stemmer;
SELECT ts_lexize('albanian_stem', 'Mollëve');
SELECT ts_lexize('albanian_stem', 'dhe');
SELECT ts_lexize('albanian_stem', 'përdorimi') = ts_lexize('albanian_stem', 'përdorur') AS same;
SELECT to_tsvector('albanian', 'Sëmundjet e mollës dhe të pemëve');
SELECT to_tsvector('albanian', 'semundjet e molles') @@ to_tsquery('albanian', 'Sëmundje & mollë') AS match;
